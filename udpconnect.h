#ifndef UDPCONNECT_H
#define UDPCONNECT_H

#include <QObject>
#include <QUdpSocket>
#include <QRegExp>

#include <string>
#include <stdio.h>

template<typename T>
T random(T min, T max)
{
    return (T)(rand() * (max - min)) + min;
}

class CUdpConnect : public QObject
{
    Q_OBJECT
public:
    CUdpConnect(QString ip, uint port, QObject *parent);

    void Send(QByteArray data);
    QByteArray CreatePacket(QString payLoad);

    void requestInfo(); //i
    void requestRule(); //r

signals:
public slots:
    void readPendingDatagrams();

private:
    QUdpSocket* socket;
    QString ip;
    QString port;
};

#endif // UDPCONNECT_H
