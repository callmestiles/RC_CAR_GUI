#pragma once

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTimer>

class CarController : public QObject
{
    Q_OBJECT

    // Properties that can be accessed from QML
    Q_PROPERTY(bool isConnected READ isConnected NOTIFY connectionChanged)
    Q_PROPERTY(QString currentDirection READ currentDirection NOTIFY directionChanged)
    Q_PROPERTY(int speed READ speed WRITE setSpeed NOTIFY speedChanged)

public:
    explicit CarController(QObject *parent = nullptr);

    // Getter methods for properties
    bool isConnected() const { return m_isConnected; }
    QString currentDirection() const { return m_currentDirection; }
    int speed() const { return m_speed; }

    // Setter methods
    void setSpeed(int speed);

public slots:
    // These slots can be called from QML
    void moveForward();
    void moveBackward();
    void turnLeft();
    void turnRight();
    void stopCar();
    void backAndForth();
    void emergencyStop();

signals:
    // Signals that QML can listen to
    void connectionChanged();
    void directionChanged();
    void speedChanged();
    void requestSent(const QString& direction);
    void requestFailed(const QString& error);

private slots:
    void onRequestFinished(QNetworkReply* reply);
    void onBackAndForthTimer();

private:
    void sendControlRequest(const QString& direction, int speed);

    // Network manager for HTTP requests
    QNetworkAccessManager* m_networkManager;

    // Car control endpoint URL
    const QString m_carUrl = "http://192.168.4.1/control";

    // State variables
    bool m_isConnected;
    QString m_currentDirection;
    int m_speed;

    // Timer for back and forth movement
    QTimer* m_backAndForthTimer;
    bool m_backAndForthForward;
};
