#pragma once

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>

class ThumbstickController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool isConnected READ isConnected NOTIFY connectionChanged)
    Q_PROPERTY(QString serialPort READ serialPort WRITE setSerialPort NOTIFY serialPortChanged)
    Q_PROPERTY(bool thumbstickEnabled READ thumbstickEnabled WRITE setThumbstickEnabled NOTIFY thumbstickEnabledChanged)

    // Arm control properties
    Q_PROPERTY(int armRawX READ armRawX NOTIFY armDataChanged)
    Q_PROPERTY(int armRawY READ armRawY NOTIFY armDataChanged)
    Q_PROPERTY(QString armCommand READ armCommand NOTIFY armDataChanged)

    // Motor control properties
    Q_PROPERTY(int motorRawX READ motorRawX NOTIFY motorDataChanged)
    Q_PROPERTY(int motorRawY READ motorRawY NOTIFY motorDataChanged)
    Q_PROPERTY(QString motorDirection READ motorDirection NOTIFY motorDataChanged)
    Q_PROPERTY(int motorSpeed READ motorSpeed NOTIFY motorDataChanged)

    Q_PROPERTY(QString buttonState READ buttonState NOTIFY buttonStateChanged)
    Q_PROPERTY(QString carUrl READ carUrl WRITE setCarUrl NOTIFY carUrlChanged)

public:
    explicit ThumbstickController(QObject *parent = nullptr);
    ~ThumbstickController();

    // Property getters
    bool isConnected() const { return m_isConnected; }
    QString serialPort() const { return m_serialPortName; }
    bool thumbstickEnabled() const { return m_thumbstickEnabled; }

    int armRawX() const { return m_armRawX; }
    int armRawY() const { return m_armRawY; }
    QString armCommand() const { return m_armCommand; }

    int motorRawX() const { return m_motorRawX; }
    int motorRawY() const { return m_motorRawY; }
    QString motorDirection() const { return m_motorDirection; }
    int motorSpeed() const { return m_motorSpeed; }

    QString buttonState() const { return m_buttonState; }
    QString carUrl() const { return m_carUrl; }

    // Property setters
    void setSerialPort(const QString& portName);
    void setThumbstickEnabled(bool enabled);
    void setCarUrl(const QString& url);

public slots:
    void connectSerial();
    void disconnectSerial();
    QStringList getAvailableSerialPorts();
    void sendGripperCommand(const QString& command);

signals:
    void connectionChanged();
    void serialPortChanged();
    void thumbstickEnabledChanged();
    void armDataChanged();
    void motorDataChanged();
    void serialDataReceived(const QString& data);
    void armControlReceived(const QString& command);
    void motorControlReceived(const QString& direction, int speed);
    void buttonStateChanged();
    void gripperControlReceived(const QString& state);
    void carUrlChanged();
    void httpRequestSent(const QString& endpoint, const QString& direction, int speed);
    void httpRequestFailed(const QString& endpoint, const QString& error);

private slots:
    void onSerialDataReady();
    void onSerialError(QSerialPort::SerialPortError error);
    void onHttpRequestFinished(QNetworkReply* reply);

private:
    void processArmData(int x, int y);
    void processMotorData(int x, int y);
    void parseArduinoData(const QString& data);
    QString calculateDirection(int x, int y, int centerX, int centerY, int deadzone);
    int calculateSpeed(int x, int y, int centerX, int centerY, int deadzone);
    void sendHttpRequest(const QString& endpoint, const QString& direction, int speed);

    // Serial communication
    QSerialPort* m_serialPort;
    QString m_serialPortName;
    bool m_isConnected;
    QByteArray m_serialBuffer;
    bool m_thumbstickEnabled;

    // HTTP communication
    QNetworkAccessManager* m_networkManager;
    QString m_carUrl;

    // Arm control data
    int m_armRawX;
    int m_armRawY;
    QString m_armCommand;

    // Motor control data
    int m_motorRawX;
    int m_motorRawY;
    QString m_motorDirection;
    int m_motorSpeed;

    // Last values for change detection and rate limiting
    QString m_lastArmCommand;
    QString m_lastMotorDirection;
    int m_lastMotorSpeed;
    QString m_lastButtonState;

    QString m_buttonState;
    int m_centerX;
    int m_centerY;
    int m_deadzone;
    int m_significantSpeedChange; // Minimum speed difference to trigger HTTP request
};
