#ifndef UDPCONNECT_H
#define UDPCONNECT_H

#include <QObject>
#include <QUdpSocket>
#include <QRegExp>
#include <QLabel>
#include <QTime>

#include <string>
#include <stdio.h>

#include "sampservers.h"

template<typename T>
T random(T min, T max)
{
    return (T)(rand() * (max - min)) + min;
}
namespace read {
    template <typename T>
    T read(QByteArray &array, uint &offset);
    template <>
    QString read(QByteArray &array, uint &offset);
}

class CUdpConnect : public QObject
{
    Q_OBJECT
public:
    CUdpConnect(QListWidgetItem *item, QString group, ushort rPort, QObject *parent);
    ~CUdpConnect();

    void Send(QByteArray data);
    QByteArray CreatePacket(QString payLoad);

    void requestPing(bool changedServer = true); //p
    void requestInfo(bool changedServer = true); //i
    void requestRule(bool changedServer = true); //r

    void setPlayers(QLabel *label);
    void setPing(QLabel *label);
    void setTime(QLabel *label);
    void setWeather(QLabel *label);
    void setLng(QLabel *label);
    void setMode(QLabel *label);
    void setUrl(QLabel *label);
    void setMap(QLabel *label);

signals:
public slots:
    void readPendingDatagrams();

private:
    QUdpSocket* socket;
    QListWidgetItem *item;
    QString group;
    QString ip;
    QString port;
    uint time_connect;
    ushort rPort;

    QLabel *players = nullptr;
    QLabel *ping = nullptr;
    QLabel *time = nullptr;
    QLabel *weather = nullptr;
    QLabel *map = nullptr;
    QLabel *mode = nullptr;
    QLabel *url = nullptr;
    QLabel *lng = nullptr;

    template<typename T>
    T read(QByteArray &array, uint &offset){
        return read::read<T>(array, offset);
    }
    QString readLimited(QByteArray &array, uint &offset);
};

#endif // UDPCONNECT_H
