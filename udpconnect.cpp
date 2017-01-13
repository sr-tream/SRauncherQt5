#include "udpconnect.h"
#include "sampservers.h"
#include "runngame.h"

CUdpConnect::CUdpConnect(QListWidgetItem *item, ushort rPort, QObject *parent) : QObject(parent)
{
    this->item = item;
    this->rPort = rPort;
    stServer srv = g_SrvList[item->text()];
    ip = CRunGame::domain2ip(srv.ip);
    port = QString::number(srv.port);

    socket = new QUdpSocket(this);
    socket->bind(rPort);
    QObject::connect(socket, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
}

void CUdpConnect::Send(QByteArray data)
{
    for (int i = 0; i < 3; ++i) //Instread TCP
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

    if (buffer[10] == 'p'){
        if (ping != nullptr)
            ping->setText(QString::number(QTime::currentTime().msecsSinceStartOfDay() - time_connect));
    }
    else if (buffer[10] == 'i'){ // Info
        buffer[11]; // Password
        uint offset = 12;

        ushort curplayers = read<ushort>(buffer, offset);
        ushort maxplayers = read<ushort>(buffer, offset);
        if (players != nullptr)
            players->setText(QString::number(curplayers) + " of " +
                         QString::number(maxplayers));

        QString name = read<QString>(buffer, offset);
        stServer srv = g_SrvList[item->text()];
        if (item->text() == QString(srv.ip + ":" + QString::number(srv.port))
            && srv.name.isEmpty()){

            foreach (auto it, g_SrvList)
                if (it.name == name)
                    name += "#double";
            srv.name = name;
            g_SrvList[name] = srv;
            g_SrvList.remove(QString(srv.ip + ":" + QString::number(srv.port)));
            item->setText(name);
        }
        if (mode != nullptr)
            mode->setText(read<QString>(buffer, offset));
        if (lng != nullptr)
            lng->setText(read<QString>(buffer, offset));
    }
    else if (buffer[10] == 'r'){ // Rules
        uint offset = 11;
        uint rule_count = read<ushort>(buffer, offset);

        for (int i = 0; i < rule_count; ++i){
            QString rule = readLimited(buffer, offset);
            QString value = readLimited(buffer, offset);

            if (rule == "worldtime" && time != nullptr)
                time->setText(value);
            else if (rule == "weather" && weather != nullptr)
                weather->setText(value);
            else if (rule == "mapname" && map != nullptr)
                map->setText(value);
            else if (rule == "weburl" && url != nullptr)
                url->setText("<a href=\"http://" + value + "\">" + value + "</a>");
        }
    }
}

void CUdpConnect::requestPing(bool changedServer)
{
    QByteArray data;
    data.append("SAMP");
    QRegExp rx(R"((\d{1,3})\.(\d{1,3})\.(\d{1,3})\.(\d{1,3}))");
    if (rx.indexIn(ip) != -1){
        data.push_back((char)rx.cap(1).toShort());
        data.push_back((char)rx.cap(2).toShort());
        data.push_back((char)rx.cap(3).toShort());
        data.push_back((char)rx.cap(4).toShort());
    }
    byteValue<uint16_t> _port;
    _port.value = port.toShort();
    data.push_back(_port.bytes[0]);
    data.push_back(_port.bytes[1]);
    data.push_back(QString("p" + QString::number(rPort)).toStdString().c_str());
    Send(data);
    time_connect = QTime::currentTime().msecsSinceStartOfDay();
    if (ping != nullptr && changedServer)
        ping->setText("");
}

void CUdpConnect::requestInfo(bool changedServer)
{
    QByteArray data = CreatePacket("i");
    Send(data);
    if (changedServer){
        if (players != nullptr)
            players->setText("");
        if (mode != nullptr)
            mode->setText("");
        if (lng != nullptr)
            lng->setText("");
    }
}

void CUdpConnect::requestRule(bool changedServer)
{
    QByteArray data = CreatePacket("r");
    Send(data);
    if (changedServer){
        if (time != nullptr)
            time->setText("");
        if (map != nullptr)
            map->setText("");
        if (weather != nullptr)
            weather->setText("");
        if (url != nullptr)
            url->setText("");
    }
}

void CUdpConnect::setPlayers(QLabel *label)
{
    players = label;
}

void CUdpConnect::setPing(QLabel *label)
{
    ping = label;
}

void CUdpConnect::setTime(QLabel *label)
{
    time = label;
}

void CUdpConnect::setWeather(QLabel *label)
{
    weather = label;
}

void CUdpConnect::setLng(QLabel *label)
{
    lng = label;
}

void CUdpConnect::setMode(QLabel *label)
{
    mode = label;
}

void CUdpConnect::setUrl(QLabel *label)
{
    url = label;
}

void CUdpConnect::setMap(QLabel *label)
{
    map = label;
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

template<typename T> inline
T CUdpConnect::read(QByteArray &array, uint &offset)
{
    byteValue<T> v;
    for (int i = 0; i < sizeof(T); ++i){
        v.bytes[i] = array[offset + i];
    }
    offset += sizeof(T);
    return v.value;
}
template<> inline
QString CUdpConnect::read(QByteArray &array, uint &offset)
{
    byteValue<uint> v;
    v.bytes[0] = array[offset++];
    v.bytes[1] = array[offset++];
    v.bytes[2] = array[offset++];
    v.bytes[3] = array[offset++];

    char *buf = new char[v.value + 1];
    for (int i = 0; i < v.value; ++i)
        buf[i] = array[offset + i];
    buf[v.value] = 0;
    offset += v.value;
    QTextCodec *codec = QTextCodec::codecForName("cp1251");
    QString ret = codec->toUnicode(buf);
    delete[] buf;
    return ret;
}
QString CUdpConnect::readLimited(QByteArray &array, uint &offset)
{
    int len = array[offset++];

    char *buf = new char[len + 1];
    for (int i = 0; i < len; ++i)
        buf[i] = array[offset + i];
    buf[len] = 0;
    offset += len;
    QTextCodec *codec = QTextCodec::codecForName("cp1251");
    QString ret = codec->toUnicode(buf);
    delete[] buf;
    return ret;
}
