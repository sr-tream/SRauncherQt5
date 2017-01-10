#ifndef SAMPSERVERS_H
#define SAMPSERVERS_H

#include <string>
#include <QFile>
#include <QMap>
#include <QStandardPaths>
#include <QTextCodec>
#include <QListWidget>

typedef uint8_t byte;

struct stServer{
    QString name;
    QString comment;
    QString gta_sa;
    QString samp;
    QString nick;
    QString ip;
    uint port;
};
extern QMap<QString, stServer> g_SrvList;

template <typename T>
union byteValue{
    T value;
    byte bytes[sizeof( T )];
};

class CSampServers
{
public:
    CSampServers(QString stdNick, QListWidget *list = nullptr);
    ~CSampServers();

    void Import();

private:
    QFile* file;
    QByteArray file_data;
    QString stdNick;
    QListWidget *list;

    void ClassicLoad();
    uint read(uint &offset);
    QString read(uint &offset, uint len);
    bool srdata = true;
};

#endif // SAMPSERVERS_H
