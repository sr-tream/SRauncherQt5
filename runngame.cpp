#include "runngame.h"

QString CRunGame::domain2ip(QString domain)
{
    char newIp[64];
    initialise();
    struct hostent *he = gethostbyname( domain.toStdString().c_str() );
    if ( he != NULL ){
        strcpy( newIp, inet_ntoa( *((struct in_addr *) he->h_addr_list[0]) ) );
    }
    uninitialise();
    return newIp;
}

void CRunGame::Connect(QString nick, QString ip, ushort port)
{
    STARTUPINFOA cif;
    ZeroMemory( &cif, sizeof( STARTUPINFOA ) );
    PROCESS_INFORMATION pi;
    char param[128];
    sprintf( param, "-c -n %s -h %s -p %d",
             nick.toStdString().c_str(),
             domain2ip(ip).toStdString().c_str(),
             port );
    if(CreateProcessA("gta_sa.exe", param, NULL,NULL, FALSE, DETACHED_PROCESS | CREATE_SUSPENDED, NULL, NULL, &cif, &pi))
    {
      if(pi.hProcess!=NULL)
      {
          if (_winMode){
              memsetEx(pi.dwProcessId, (void*)0x74595E, 0x90, 34);
              memsetEx(pi.dwProcessId, (void*)0x746225, 0x90, 2);
              memcpyEx(pi.dwProcessId, (void*)0x746236,
                       (char*)"\x90\x90\x33\xC0\xA3\xF4\x20\xC9\x00\xA3\x20\x62\x8D\x00\x90\x90\x40\x85\xC0",
                       19);
              memsetEx(pi.dwProcessId, (void*)0x748AB4, 0x90, 2);
          }
          foreach (auto lib, libs) {
              if(!Inject(pi.dwProcessId, (char*)lib.toStdString().c_str()))
              {
                TerminateProcess(pi.hProcess, 0);
                ExitProcess(0);
              }
          }
        ResumeThread(pi.hThread);
      }
    } else MessageBoxA(NULL, "Failed to Create Process", "Error", MB_ICONERROR);
}

QString CRunGame::Gta()
{
    return gta_sa;
}

QList<QString> CRunGame::Libs()
{
    return libs;
}

void CRunGame::setGta(QString gta_sa)
{
    this->gta_sa = gta_sa;
}

void CRunGame::addLib(QString lib)
{
    libs.push_back(lib);
}

void CRunGame::initialise( void )
{
    WSADATA data;
    if ( WSAStartup( MAKEWORD( 1, 1 ), &data ) != 0 )
        exit( 1 );
}

void CRunGame::uninitialise( void )
{
    WSACleanup();
}

BOOL CRunGame::Inject( DWORD pId, LPSTR dllName )
{
    HANDLE h = OpenProcess( PROCESS_ALL_ACCESS, FALSE, pId );
    if ( h )
    {
        LPVOID LoadLibAddr = (LPVOID)GetProcAddress( GetModuleHandleA( "kernel32.dll" ), "LoadLibraryA" );
        LPVOID dereercomp = VirtualAllocEx( h, NULL, strlen( dllName ), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE );
        WriteProcessMemory( h, dereercomp, dllName, strlen( dllName ), NULL );
        HANDLE asdc = CreateRemoteThread( h, NULL, NULL, (LPTHREAD_START_ROUTINE)LoadLibAddr, dereercomp, 0, NULL );
        WaitForSingleObject( asdc, INFINITE );
        VirtualFreeEx( h, dereercomp, strlen( dllName ), MEM_RELEASE );
        CloseHandle( asdc );
        CloseHandle( h );
        return TRUE;
    }
    return FALSE;
}

BOOL CRunGame::memsetEx(DWORD pId, void *addr, char c, uint size)
{
    HANDLE h = OpenProcess( PROCESS_ALL_ACCESS, FALSE, pId );
    DWORD dwProtect;
    if ( h )
    {
        VirtualProtectEx(h, addr, size, PAGE_EXECUTE_READWRITE, &dwProtect);
        for(int i = 0; i < size; ++i)
            WriteProcessMemory( h, (void*)((uint)addr + i), &c, 1, NULL );
        VirtualProtectEx(h, addr, size, dwProtect, NULL);
        CloseHandle( h );
        return TRUE;
    }
    return FALSE;
}

BOOL CRunGame::memcpyEx(DWORD pId, void *addr, char *buf, uint size)
{
    HANDLE h = OpenProcess( PROCESS_ALL_ACCESS, FALSE, pId );
    DWORD dwProtect;
    if ( h )
    {
        VirtualProtectEx(h, addr, size, PAGE_EXECUTE_READWRITE, &dwProtect);
        for(int i = 0; i < size; ++i)
            WriteProcessMemory( h, (void*)((uint)addr + i), &(buf[i]), 1, NULL );
        //WriteProcessMemory( h, addr, buf, size, NULL );
        VirtualProtectEx(h, addr, size, dwProtect, NULL);
        CloseHandle( h );
        return TRUE;
    }
    return FALSE;
}

void CRunGame::setWindowMode(bool mode)
{
    _winMode = mode;
}
