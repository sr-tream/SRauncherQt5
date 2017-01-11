#include "udpconnect.h"
#include "sampservers.h"
#include "runngame.h"

CUdpConnect::CUdpConnect(QString ip, uint port, QObject *parent) : QObject(parent)
{
    this->ip = ip;
    this->port = QString::number(port);

    socket = new QUdpSocket(this);
    socket->bind(4150);
    QObject::connect(socket, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));

    QByteArray data;
    data.append("SAMP");
    QRegExp rx(R"((\d{1,3})\.(\d{1,3})\.(\d{1,3})\.(\d{1,3}))");
    CRunGame rg;
    if (rx.indexIn(rg.domain2ip(ip)) != -1){
        data.push_back((char)rx.cap(1).toShort());
        data.push_back((char)rx.cap(2).toShort());
        data.push_back((char)rx.cap(3).toShort());
        data.push_back((char)rx.cap(4).toShort());
    }
    byteValue<uint16_t> _port;
    _port.value = port;
    data.push_back(_port.bytes[0]);
    data.push_back(_port.bytes[1]);
    data.push_back(QString("p4150").toStdString().c_str());
    Send(data);
}

void CUdpConnect::Send(QByteArray data)
{
    socket->writeDatagram(data, QHostAddress(ip), port.toShort());
}

void CUdpConnect::readPendingDatagrams()
{
    QByteArray buffer;
    buffer.resize(socket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;

    socket->readDatagram(buffer.data(), buffer.size(),
                             &sender, &senderPort);

    //TODO: parse data
}

void CUdpConnect::requestInfo()
{
    QByteArray data = CreatePacket("i");
    Send(data);
}

void CUdpConnect::requestRule()
{
    QByteArray data = CreatePacket("r");
    Send(data);
}

QByteArray CUdpConnect::CreatePacket(QString payLoad)
{
    QByteArray data;
    data.append("SAMP");
    QRegExp rx(R"((\d{1,3})\.(\d{1,3})\.(\d{1,3})\.(\d{1,3}))");
    CRunGame rg;
    if (rx.indexIn(rg.domain2ip(ip)) != -1){
        data.push_back((char)rx.cap(1).toShort());
        data.push_back((char)rx.cap(2).toShort());
        data.push_back((char)rx.cap(3).toShort());
        data.push_back((char)rx.cap(4).toShort());
    }
    byteValue<uint16_t> _port;
    _port.value = port.toShort();
    data.push_back(_port.bytes[0]);
    data.push_back(_port.bytes[1]);
    data.push_back(payLoad.toStdString().c_str());
    return data;
}
