#include "sampservers.h"
QMap<QString, stServer> g_SrvList;

CSampServers::CSampServers(QString stdNick, QComboBox *cbox, QListWidget *list)
{
    this->stdNick = stdNick;
    this->list = list;
    this->cbox = cbox;
    file = new QFile("SRDATA.DAT");
    if (!file->exists()){
        delete file;
        QString file_path = QStandardPaths::
                            locate(QStandardPaths::DocumentsLocation,
                            "GTA San Andreas User Files/SAMP/USERDATA.DAT");
        file = new QFile(file_path);
        file->open(QIODevice::ReadOnly);
        if (!file->isReadable())
            return;
        srdata = false;
    } else {
        file->open(QIODevice::ReadWrite);
        if (!file->isWritable() || !file->isReadable())
            return;
        srdata = true;
    }
    file_data = file->readAll();

    if (!srdata){
        ClassicLoad();
        return;
    }

    uint offset = 0;
    uint SrvCount = read(offset);
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
        srv.group = read(offset, len);
        if (cbox != nullptr){
            bool isDefined = false;
            for (int j = 0; j < cbox->count(); ++j)
                if (cbox->itemText(j) == srv.group){
                    isDefined = true;
                    break;
            }
            if (!isDefined)
                cbox->addItem(srv.group);
        }
        len = read(offset);
        srv.nick = read(offset, len);

        g_SrvList[srv.name] = srv;
        if (list != nullptr){
            if (cbox != nullptr && cbox->currentText() == srv.group)
                list->addItem(srv.name);
        }
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
    if (!file->isWritable())
        return;
    file->reset();
    uint size = g_SrvList.size();
    file->write((const char*)&size, 4);
    foreach (auto srv, g_SrvList) {
        if (srv.ip.isEmpty()){
            size--;
            continue;
        }
        if (cbox != nullptr){
            bool isDefined = false;
            for (int j = 0; j < cbox->count(); ++j)
                if (cbox->itemText(j) == srv.group){
                    isDefined = true;
                    break;
                }
            if (!isDefined){
                size--;
                continue;
            }
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
        len = srv.group.length();
        file->write((const char*)&len, 4);
        QByteArray samp(srv.group.toStdString().c_str());
        file->write(codec->fromUnicode(samp).toStdString().c_str(),
                    srv.group.length());
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

stServer CSampServers::FindServer(QString name, QString group)
{
    foreach (auto srv, g_SrvList) {
        if (srv.name == name && (srv.group == group || group.isEmpty()))
            return srv;
    }
    return stServer({"","","","","","",0});
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
    for(uint i = 0; i < len; ++i)
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
    ifile->open(QIODevice::ReadOnly);
    if (!file->isReadable())
        return;
    file_data = ifile->readAll();
    ClassicLoad();
    ifile->close();
}

void CSampServers::ClassicLoad()
{
    uint offset = 8;
    uint SrvCount = read(offset);
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
        if (cbox != nullptr && !cbox->currentText().isEmpty())
            srv.group = cbox->currentText();
        else srv.group = "Imported";

        srv.nick = stdNick;

        if (g_SrvList[srv.name].name != srv.name){
            g_SrvList[srv.name] = srv;
            if (list != nullptr)
                list->addItem(srv.name);
        }
    }
    if (cbox != nullptr && cbox->currentText().isEmpty()){
        cbox->addItem("Imported");
    }
}
