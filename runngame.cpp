#include "runngame.h"

void CRunGame::Connect(QString nick, QString ip, ushort port)
{
    char newIp[64];
    initialise();
    struct hostent *he = gethostbyname( ip.toStdString().c_str() );
    if ( he != NULL ){
        strcpy( newIp, inet_ntoa( *((struct in_addr *) he->h_addr_list[0]) ) );
    }
    uninitialise();

    STARTUPINFOA cif;
    ZeroMemory( &cif, sizeof( STARTUPINFOA ) );
    PROCESS_INFORMATION pi;
    char param[128];
    sprintf( param, "-c -n %s -h %s -p %d",
             nick.toStdString().c_str(),
             newIp,
             port );
    if(CreateProcessA("gta_sa.exe", param, NULL,NULL, FALSE, DETACHED_PROCESS | CREATE_SUSPENDED, NULL, NULL, &cif, &pi))
    {
      if(pi.hProcess!=NULL)
      {
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
