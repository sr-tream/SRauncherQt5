#ifndef RUNNGAME_H
#define RUNNGAME_H

#include <QString>
#include <QList>

#include <windows.h>
#include <tlhelp32.h>
#include <stdio.h>
#include <string>
#include "winsock.h"
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "kernel32.lib")

class CRunGame
{
public:
    void Connect(QString nick, QString ip, ushort port);

    QString Gta();
    QList<QString> Libs();

    void setGta(QString gta_sa);
    void addLib(QString lib);

    QString domain2ip(QString domain);

private:
    QString gta_sa;
    QList<QString> libs;

    void initialise();
    void uninitialise();
    BOOL Inject( DWORD pId, LPSTR dllName );
};

#endif // RUNNGAME_H
