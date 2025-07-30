#include "ThumbstickController.h"

ThumbstickController::ThumbstickController(QObject *parent)
    : QObject(parent)
       , m_serialPort(new QSerialPort(this))
       , m_serialPortName("/dev/serial0")
       , m_isConnected(false)
       , m_thumbstickEnabled(false)
       , m_networkManager(new QNetworkAccessManager(this))
       , m_carUrl("http://192.168.4.1") // Base URL without endpoint
       , m_armRawX(512)
       , m_armRawY(512)
       , m_armCommand("stop")
       , m_motorRawX(512)
       , m_motorRawY(512)
       , m_motorDirection("stop")
       , m_motorSpeed(0)
       , m_lastArmCommand("stop")
       , m_lastMotorDirection("stop")
       , m_lastMotorSpeed(0)
       , m_lastButtonState("OPEN")
       , m_buttonState("OPEN")
       , m_centerX(512)
       , m_centerY(512)
       , m_deadzone(100)
       , m_significantSpeedChange(20) // Only send HTTP request if speed changes by 20 or more
{
    // Setup serial port connections
    connect(m_serialPort, &QSerialPort::readyRead,
            this, &ThumbstickController::onSerialDataReady);
    connect(m_serialPort, QOverload<QSerialPort::SerialPortError>::of(&QSerialPort::errorOccurred),
            this, &ThumbstickController::onSerialError);

    // Setup network manager
    connect(m_networkManager, &QNetworkAccessManager::finished,
            this, &ThumbstickController::onHttpRequestFinished);
}

ThumbstickController::~ThumbstickController()
{
    if (m_serialPort->isOpen()) {
        m_serialPort->close();
    }
}

void ThumbstickController::setSerialPort(const QString& portName)
{
    if (m_serialPortName != portName) {
        m_serialPortName = portName;
        emit serialPortChanged();
    }
}

void ThumbstickController::setCarUrl(const QString& url)
{
    if (m_carUrl != url) {
        m_carUrl = url;
        emit carUrlChanged();
    }
}

void ThumbstickController::setThumbstickEnabled(bool enabled)
{
    if (m_thumbstickEnabled != enabled) {
        m_thumbstickEnabled = enabled;
        emit thumbstickEnabledChanged();

        // Send stop commands when disabled
        if (!enabled) {
            if (m_armCommand != "stop") {
                sendHttpRequest("/arm", "stop", 0);
                m_armCommand = "stop";
                m_lastArmCommand = "stop";
                emit armControlReceived(m_armCommand);
            }
            if (m_motorDirection != "stop") {
                sendHttpRequest("/control", "stop", 0);
                m_motorDirection = "stop";
                m_motorSpeed = 0;
                m_lastMotorDirection = "stop";
                m_lastMotorSpeed = 0;
                emit motorControlReceived(m_motorDirection, m_motorSpeed);
            }
        }
    }
}

void ThumbstickController::connectSerial()
{
    if (m_serialPort->isOpen()) {
        m_serialPort->close();
    }

    m_serialPort->setPortName(m_serialPortName);
    m_serialPort->setBaudRate(QSerialPort::Baud115200);
    m_serialPort->setDataBits(QSerialPort::Data8);
    m_serialPort->setParity(QSerialPort::NoParity);
    m_serialPort->setStopBits(QSerialPort::OneStop);
    m_serialPort->setFlowControl(QSerialPort::NoFlowControl);

    if (m_serialPort->open(QIODevice::ReadWrite)) {
        m_isConnected = true;
        qDebug() << "Thumbstick serial port connected:" << m_serialPortName;
        emit connectionChanged();
    } else {
        m_isConnected = false;
        qDebug() << "Failed to connect to thumbstick serial port:" << m_serialPort->errorString();
        emit connectionChanged();
    }
}

void ThumbstickController::sendGripperCommand(const QString& command) {
    sendHttpRequest("/arm", command, 0);
    emit gripperControlReceived(command.toUpper());
}

void ThumbstickController::disconnectSerial()
{
    if (m_serialPort->isOpen()) {
        m_serialPort->close();
    }
    m_isConnected = false;
    emit connectionChanged();
    qDebug() << "Thumbstick serial port disconnected";
}

QStringList ThumbstickController::getAvailableSerialPorts()
{
    QStringList portNames;
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos) {
        portNames << info.portName();
    }
    return portNames;
}

void ThumbstickController::onSerialDataReady()
{
    QByteArray data = m_serialPort->readAll();
    m_serialBuffer.append(data);

    // Process complete lines
    while (m_serialBuffer.contains('\n')) {
        int index = m_serialBuffer.indexOf('\n');
        QByteArray line = m_serialBuffer.left(index);
        m_serialBuffer.remove(0, index + 1);

        QString lineStr = QString::fromUtf8(line).trimmed();
        if (!lineStr.isEmpty()) {
            parseArduinoData(lineStr);
            emit serialDataReceived(lineStr);
        }
    }
}

void ThumbstickController::parseArduinoData(const QString& data)
{
    if (!m_thumbstickEnabled) {
        return;
    }

    // Parse format: "X1=123, Y1=123, X2=123, Y2=123, BTN=OPEN"
    QRegularExpression regex(R"(X1=(\d+),\s*Y1=(\d+),\s*X2=(\d+),\s*Y2=(\d+),\s*BTN=(\w+))");
    QRegularExpressionMatch match = regex.match(data);

    if (match.hasMatch()) {
        // Motor data (X1, Y1)
        int motorX = match.captured(1).toInt();
        int motorY = match.captured(2).toInt();

        // Arm data (X2, Y2)
        int armX = match.captured(3).toInt();
        int armY = match.captured(4).toInt();

        // Button state
        QString buttonState = match.captured(5);

        // Process motor data
        processMotorData(motorX, motorY);

        // Process arm data
        processArmData(armX, armY);

        // Process button state for gripper
        if (m_buttonState != buttonState) {
            m_buttonState = buttonState;
            emit buttonStateChanged();

            // Send HTTP request for gripper control
            QString gripperCommand = (buttonState == "CLOSE") ? "close" : "open";
            if (m_lastButtonState != buttonState) {
                sendHttpRequest("/arm", gripperCommand, 0);
                m_lastButtonState = buttonState;
                emit gripperControlReceived(buttonState);
            }
        }
    }
}

void ThumbstickController::onSerialError(QSerialPort::SerialPortError error)
{
    if (error != QSerialPort::NoError) {
        qDebug() << "Thumbstick serial port error:" << m_serialPort->errorString();
        m_isConnected = false;
        emit connectionChanged();
    }
}

void ThumbstickController::processMotorData(int x, int y)
{
    bool dataChanged = false;

    if (m_motorRawX != x) {
        m_motorRawX = x;
        dataChanged = true;
    }

    if (m_motorRawY != y) {
        m_motorRawY = y;
        dataChanged = true;
    }

    // Calculate direction and speed
    QString newDirection = calculateDirection(x, y, m_centerX, m_centerY, m_deadzone);
    int newSpeed = calculateSpeed(x, y, m_centerX, m_centerY, m_deadzone);

    bool commandChanged = false;
    if (m_motorDirection != newDirection) {
        m_motorDirection = newDirection;
        commandChanged = true;
        dataChanged = true;
    }

    if (m_motorSpeed != newSpeed) {
        m_motorSpeed = newSpeed;
        commandChanged = true;
        dataChanged = true;
    }

    // Send HTTP request only if there's a significant change
    if (commandChanged &&
        (m_lastMotorDirection != newDirection ||
         abs(m_lastMotorSpeed - newSpeed) >= m_significantSpeedChange ||
         (newDirection == "stop" && m_lastMotorDirection != "stop"))) {

        sendHttpRequest("/control", newDirection, newSpeed);
        m_lastMotorDirection = newDirection;
        m_lastMotorSpeed = newSpeed;
        emit motorControlReceived(newDirection, newSpeed);
    }

    if (dataChanged) {
        emit motorDataChanged();
    }
}

void ThumbstickController::processArmData(int x, int y)
{
    bool dataChanged = false;

    if (m_armRawX != x) {
        m_armRawX = x;
        dataChanged = true;
    }

    if (m_armRawY != y) {
        m_armRawY = y;
        dataChanged = true;
    }

    // Calculate arm command (direction only, no speed for arm movement)
    QString newCommand = calculateDirection(x, y, m_centerX, m_centerY, m_deadzone);

    if (m_armCommand != newCommand) {
        m_armCommand = newCommand;
        dataChanged = true;

        // Send HTTP request only when command actually changes
        if (m_lastArmCommand != newCommand) {
            // For arm control, we'll use a fixed speed or 0 for stop
            int armSpeed = (newCommand == "stop") ? 0 : 200; // Fixed speed for arm movements
            sendHttpRequest("/arm", newCommand, armSpeed);
            m_lastArmCommand = newCommand;
            emit armControlReceived(newCommand);
        }
    }

    if (dataChanged) {
        emit armDataChanged();
    }
}

QString ThumbstickController::calculateDirection(int x, int y, int centerX, int centerY, int deadzone)
{
    int xDev = x - centerX;
    int yDev = y - centerY;

    // Check deadzone
    if (abs(xDev) <= deadzone && abs(yDev) <= deadzone) {
        return "stop";
    }

    // Determine dominant axis
    if (abs(yDev) > abs(xDev) + 10) {  // Y dominant with some hysteresis
        if (yDev > deadzone) {
            return "forward";
        } else if (yDev < -deadzone) {
            return "backward";
        }
    } else {  // X dominant
        if (xDev > deadzone) {
            return "left";
        } else if (xDev < -deadzone) {
            return "right";
        }
    }

    return "stop";
}

int ThumbstickController::calculateSpeed(int x, int y, int centerX, int centerY, int deadzone)
{
    int xDev = x - centerX;
    int yDev = y - centerY;

    // Find the larger deviation
    int maxDev = qMax(abs(xDev), abs(yDev));

    if (maxDev <= deadzone) {
        return 0;
    }

    // Calculate effective deviation after deadzone
    int effectiveDev = maxDev - deadzone;
    int maxRange = (1023 - qMax(centerX, centerY)) - deadzone;

    // Map to 0-255 range
    int speed = static_cast<int>((static_cast<float>(effectiveDev) / maxRange) * 255);

    return qBound(0, speed, 255);
}

void ThumbstickController::sendHttpRequest(const QString& endpoint, const QString& direction, int speed)
{
    QJsonObject jsonData;
    jsonData["direction"] = direction;
    jsonData["speed"] = speed;

    QJsonDocument doc(jsonData);
    QByteArray data = doc.toJson();

    QString fullUrl = m_carUrl + endpoint;
    QNetworkRequest request{QUrl(fullUrl)};
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply* reply = m_networkManager->post(request, data);

    // Store endpoint info in the reply for identification in the response handler
    reply->setProperty("endpoint", endpoint);
    reply->setProperty("direction", direction);
    reply->setProperty("speed", speed);

    emit httpRequestSent(endpoint, direction, speed);
    qDebug() << "Sent HTTP request to" << fullUrl << ":" << data;
}

void ThumbstickController::onHttpRequestFinished(QNetworkReply* reply)
{
    QString endpoint = reply->property("endpoint").toString();
    QString direction = reply->property("direction").toString();
    int speed = reply->property("speed").toInt();

    if (reply->error() == QNetworkReply::NoError) {
        qDebug() << "HTTP request successful for" << endpoint << "- Direction:" << direction << "Speed:" << speed;
    } else {
        qDebug() << "HTTP request failed for" << endpoint << ":" << reply->errorString();
        emit httpRequestFailed(endpoint, reply->errorString());
    }

    reply->deleteLater();
}
