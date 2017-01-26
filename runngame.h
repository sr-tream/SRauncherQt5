#ifndef RUNNGAME_H
#define RUNNGAME_H

#include <QString>
#include <QList>
#include <QRegExp>
#include <QApplication>
#include <QDesktopWidget>

#include <windows.h>
#include <tlhelp32.h>
#include <stdio.h>
#include <string>
#include "winsock.h"
//#pragma comment(lib, "ws2_32.lib")
//#pragma comment(lib, "user32.lib")
//#pragma comment(lib, "kernel32.lib")

class CRunGame
{
public:
    void Connect(QString nick, QString ip, ushort port);
    void Debug();

    QString Gta();
    QList<QString> Libs();

    void setGta(QString gta_sa);
    void addLib(QString lib);
    void setWindowMode(bool mode);
    void setWindowSize(QString size);
    void setWindowTop(bool top);

    void reset();

    static QString domain2ip(QString domain);

private:
    QString gta_sa;
    QList<QString> libs;
    QString size = "640*480";
    bool _winMode = false;
    bool winTop = false;

    static void initialise();
    static void uninitialise();
    BOOL Inject( DWORD pId, LPSTR dllName );
    BOOL memsetEx(DWORD pId, void *addr, char c, uint size);
    BOOL memcpyEx(DWORD pId, void *addr, char* buf, uint size);
    BOOL WriteIntEx(DWORD pId, void *addr, int v);

    void winMode(DWORD pId);
    void fastRun(DWORD pId);
    PROCESS_INFORMATION runGame(LPSTR param);
};

#endif // RUNNGAME_H
