#include "sampservers.h"
QMap<QString, stServer> g_SrvList;

CSampServers::CSampServers(QString stdNick, QListWidget *list)
{
    this->stdNick = stdNick;
    this->list = list;
    file = new QFile("SRDATA.DAT");
    if (!file->exists()){
        delete file;
        QString file_path = QStandardPaths::
                            locate(QStandardPaths::DocumentsLocation,
                            "GTA San Andreas User Files/SAMP/USERDATA.DAT");
        file = new QFile(file_path);
        srdata = false;
    }
    file->open(QIODevice::ReadWrite);
    file_data = file->readAll();

    if (!srdata){
        ClassicLoad();
        return;
    }

    uint SrvCount = ((uint*)file_data.data())[0];
    uint offset = 4;
    stServer srv;

    for(uint i = 0; i < SrvCount; ++i){
        uint len = read(offset);
        srv.ip = read(offset, len);
        srv.port = read(offset);
        len = read(offset);
        srv.name = read(offset, len);
        len = read(offset);
        srv.comment = read(offset, len);
        len = read(offset);
        srv.gta_sa = read(offset, len);
        len = read(offset);
        srv.samp = read(offset, len);
        len = read(offset);
        srv.nick = read(offset, len);

        g_SrvList[srv.name] = srv;
        if (list != nullptr)
            list->addItem(srv.name);
    }
}

CSampServers::~CSampServers()
{
    if (!srdata){
        delete file;
        file = new QFile("SRDATA.DAT");
        srdata = true;
    }
    if (file->exists())
        file->remove();
    file->open(QIODevice::WriteOnly);
    file->reset();
    uint size = g_SrvList.size();
    file->write((const char*)&size, 4);
    foreach (auto srv, g_SrvList) {
        if (srv.ip.isEmpty()){
            size--;
            continue;
        }
        uint len = srv.ip.length();
        file->write((const char*)&len, 4);
        file->write(srv.ip.toStdString().c_str(), srv.ip.length());
        file->write((const char*)&srv.port, 4);
        len = srv.name.length();
        file->write((const char*)&len, 4);
        QTextCodec *codec = QTextCodec::codecForName("cp1251");
        QByteArray name(srv.name.toStdString().c_str());
        file->write(codec->fromUnicode(name).toStdString().c_str(),
                    srv.name.length());
        len = srv.comment.length();
        file->write((const char*)&len, 4);
        QByteArray comment(srv.comment.toStdString().c_str());
        file->write(codec->fromUnicode(comment).toStdString().c_str(),
                    srv.comment.length());
        len = srv.gta_sa.length();
        file->write((const char*)&len, 4);
        QByteArray gta_sa(srv.gta_sa.toStdString().c_str());
        file->write(codec->fromUnicode(gta_sa).toStdString().c_str(),
                    srv.gta_sa.length());
        len = srv.samp.length();
        file->write((const char*)&len, 4);
        QByteArray samp(srv.samp.toStdString().c_str());
        file->write(codec->fromUnicode(samp).toStdString().c_str(),
                    srv.samp.length());
        len = srv.nick.length();
        file->write((const char*)&len, 4);
        QByteArray nick(srv.nick.toStdString().c_str());
        file->write(codec->fromUnicode(nick).toStdString().c_str(),
                    srv.nick.length());
    }
    file->flush();
    file->reset();
    file->write((const char*)&size, 4);
    file->close();
}

uint CSampServers::read(uint &offset)
{
    byteValue<uint> v;
    v.bytes[0] = ((byte*)file_data.data())[offset++];
    v.bytes[1] = ((byte*)file_data.data())[offset++];
    v.bytes[2] = ((byte*)file_data.data())[offset++];
    v.bytes[3] = ((byte*)file_data.data())[offset++];
    return v.value;
}

QString CSampServers::read(uint &offset, uint len)
{
    char *buf = new char[len + 1];
    for(int i = 0; i < len; ++i)
        buf[i] = file_data.data()[i + offset];
    offset += len;
    buf[len] = '\0';
    QTextCodec *codec = QTextCodec::codecForName("cp1251");
    QString ret = codec->toUnicode(buf);
    delete[] buf;
    return ret;
}

void CSampServers::Import()
{
    QString file_path = QStandardPaths::
                        locate(QStandardPaths::DocumentsLocation,
                        "GTA San Andreas User Files/SAMP/USERDATA.DAT");
    file_data.clear();
    QFile *ifile = new QFile(file_path);
    ifile->open(QIODevice::ReadWrite);
    file_data = ifile->readAll();
    ClassicLoad();
    ifile->close();
}

void CSampServers::ClassicLoad()
{
    uint SrvCount = ((uint*)file_data.data())[2];
    uint offset = 12;
    stServer srv;

    for(uint i = 0; i < SrvCount; ++i){
        uint len = read(offset);
        srv.ip = read(offset, len);
        srv.port = read(offset);
        len = read(offset);
        srv.name = read(offset, len);
        len = read(offset);
        read(offset, len); //password
        len = read(offset);
        read(offset, len); //RCON
        srv.comment = "Imported from USERDATA.DAT";
        srv.gta_sa = "gta_sa.exe";
        srv.samp = "samp.dll";
        srv.nick = stdNick;

        if (g_SrvList[srv.name].name != srv.name){
            g_SrvList[srv.name] = srv;
            if (list != nullptr)
                list->addItem(srv.name);
        }
    }
}
