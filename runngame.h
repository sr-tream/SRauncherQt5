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
    void setWindowMode(bool mode);

    QString domain2ip(QString domain);

private:
    QString gta_sa;
    QList<QString> libs;
    bool _winMode = false;

    void initialise();
    void uninitialise();
    BOOL Inject( DWORD pId, LPSTR dllName );
    BOOL memsetEx(DWORD pId, void *addr, char c, uint size);
    BOOL memcpyEx(DWORD pId, void *addr, char* buf, uint size);
};

#endif // RUNNGAME_H
