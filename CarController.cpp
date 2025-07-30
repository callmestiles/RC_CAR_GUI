#include "CarController.h"
#include <QDebug>

CarController::CarController(QObject *parent)
    : QObject(parent)
    , m_networkManager(new QNetworkAccessManager(this))
    , m_isConnected(false)
    , m_currentDirection("stop")
    , m_speed(255)
    , m_backAndForthTimer(new QTimer(this))
    , m_backAndForthForward(true)
{
    // Connect network manager signals
    connect(m_networkManager, &QNetworkAccessManager::finished,
            this, &CarController::onRequestFinished);

    // Setup back and forth timer
    m_backAndForthTimer->setInterval(1000); // 1 second intervals
    connect(m_backAndForthTimer, &QTimer::timeout,
            this, &CarController::onBackAndForthTimer);
}

void CarController::setSpeed(int speed)
{
    // Clamp speed between 0 and 255
    speed = qBound(0, speed, 255);
    if (m_speed != speed) {
        m_speed = speed;
        emit speedChanged();
    }
}

void CarController::moveForward()
{
    qDebug() << "Moving forward";
    m_backAndForthTimer->stop(); // Stop any ongoing back and forth
    sendControlRequest("forward", m_speed);
}

void CarController::moveBackward()
{
    qDebug() << "Moving backward";
    m_backAndForthTimer->stop(); // Stop any ongoing back and forth
    sendControlRequest("backward", m_speed);
}

void CarController::turnLeft()
{
    qDebug() << "Turning left";
    m_backAndForthTimer->stop(); // Stop any ongoing back and forth
    sendControlRequest("left", m_speed);
}

void CarController::turnRight()
{
    qDebug() << "Turning right";
    m_backAndForthTimer->stop(); // Stop any ongoing back and forth
    sendControlRequest("right", m_speed);
}

void CarController::stopCar()
{
    qDebug() << "Stopping car";
    m_backAndForthTimer->stop(); // Stop any ongoing back and forth
    sendControlRequest("stop", 0);
}

void CarController::emergencyStop()
{
    qDebug() << "EMERGENCY STOP";
    m_backAndForthTimer->stop();
    sendControlRequest("stop", 0);
}

void CarController::backAndForth()
{
    qDebug() << "Starting back and forth movement";
    m_backAndForthForward = true;
    m_backAndForthTimer->start();
    sendControlRequest("forward", m_speed);
}

void CarController::onBackAndForthTimer()
{
    if (m_backAndForthForward) {
        sendControlRequest("backward", m_speed);
    } else {
        sendControlRequest("forward", m_speed);
    }
    m_backAndForthForward = !m_backAndForthForward;
}

// Update sendControlRequest method signature and implementation:
void CarController::sendControlRequest(const QString& direction, int speed)
{
    QJsonObject jsonData;
    jsonData["direction"] = direction;
    jsonData["speed"] = speed;

    QJsonDocument doc(jsonData);
    QByteArray data = doc.toJson();

    QNetworkRequest request{QUrl(m_carUrl)};
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply* reply = m_networkManager->post(request, data);

    m_currentDirection = direction;
    emit directionChanged();
    emit requestSent(direction);

    qDebug() << "Sent request:" << data;
}

void CarController::onRequestFinished(QNetworkReply* reply)
{
    // Check if request was successful

    qDebug()<<reply->error();
    if (reply->error() == QNetworkReply::NoError) {
        qDebug() << "Request successful";
        m_isConnected = true;
        emit connectionChanged();
    } else {
        qDebug() << "Request failed:" << reply->errorString();
        m_isConnected = false;
        emit connectionChanged();
        emit requestFailed(reply->errorString());
    }

    // Clean up
    reply->deleteLater();
}
