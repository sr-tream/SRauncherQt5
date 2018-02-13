#include "runngame.h"

QString CRunGame::domain2ip(QString domain)
{
	char newIp[64] = {0};
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
	char param[128];
	if (password.isEmpty())
		sprintf( param, "-c -n %s -h %s -p %d",
				 nick.toStdString().c_str(),
				 domain2ip(ip).toStdString().c_str(),
				 port );
	else sprintf( param, "-c -n %s -h %s -p %d -z %s",
				  nick.toStdString().c_str(),
				  domain2ip(ip).toStdString().c_str(),
				  port,
				  password.toStdString().c_str() );
	PROCESS_INFORMATION pi = runGame(param);
	if(pi.hProcess!=NULL){
		winMode(pi.dwProcessId);
		foreach (auto lib, libs) {
			if(!Inject(pi.dwProcessId, (char*)lib.toStdString().c_str())){
				TerminateProcess(pi.hProcess, 0);
				ExitProcess(0);
			}
		}
		multiWindow(pi.dwProcessId);
		fastRun(pi.dwProcessId);
		ResumeThread(pi.hThread);
	}
}

void CRunGame::Debug()
{
	PROCESS_INFORMATION pi = runGame((char*)"-d");
	if(pi.hProcess!=NULL){
		winMode(pi.dwProcessId);
		foreach (auto lib, libs) {
			if(!Inject(pi.dwProcessId, (char*)lib.toStdString().c_str())){
				TerminateProcess(pi.hProcess, 0);
				ExitProcess(0);
			}
		}
		fastRun(pi.dwProcessId);
		ResumeThread(pi.hThread);
	}
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

void CRunGame::setPassword(QString password)
{
	this->password = password;
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

BOOL CRunGame::WriteIntEx(DWORD pId, void *addr, int v)
{
	HANDLE h = OpenProcess( PROCESS_ALL_ACCESS, FALSE, pId );
	DWORD dwProtect;
	if ( h )
	{
		VirtualProtectEx(h, addr, 4, PAGE_EXECUTE_READWRITE, &dwProtect);
		WriteProcessMemory( h, addr, &v, 4, NULL );
		VirtualProtectEx(h, addr, 4, dwProtect, NULL);
		CloseHandle( h );
		return TRUE;
	}
	return FALSE;
}

void CRunGame::setWindowMode(bool mode)
{
	_winMode = mode;
}

void CRunGame::setWindowSize(QString size)
{
	this->size = size;
}

void CRunGame::setWindowTop(bool top)
{
	this->winTop = top;
}

void CRunGame::winMode(DWORD pId)
{
	if (!_winMode)
		return;
	memsetEx(pId, (void*)0x74595E, 0x90, 34);
	memsetEx(pId, (void*)0x746225, 0x90, 2);
	memcpyEx(pId, (void*)0x746236,
			 (char*)"\x90\x90\x33\xC0\xA3\xF4\x20\xC9\x00\xA3\x20\x62\x8D\x00\x90\x90\x40\x85\xC0",
			 19);
	memsetEx(pId, (void*)0x748AB4, 0x90, 2);

	QRegExp rx(R"((\d*)\*(\d*))");
	if (rx.indexIn(size) != -1){
		QDesktopWidget *d = QApplication::desktop();
		WriteIntEx(pId, (void*)0x7455C8, (d->width() - rx.cap(1).toShort()) / 2);
		if (winTop)
			WriteIntEx(pId, (void*)0x7455C3, 0);
		else WriteIntEx(pId, (void*)0x7455C3, (d->height() - rx.cap(2).toShort()) / 2);
		memsetEx(pId, (void*)0x61960C, 0x90, 0x14);
		WriteIntEx(pId, (void*)0xC17044, rx.cap(1).toInt());
		WriteIntEx(pId, (void*)0xC17048, rx.cap(2).toInt());
	}
}

void CRunGame::multiWindow(DWORD pId)
{
	memcpyEx(pId, (void*)0x74872D, (char*)"\x90\x90\x90\x31\xC0", 5);
}

void CRunGame::fastRun(DWORD pId)
{
	WriteIntEx(pId, (void*)0xC8D4C0, 5);
	WriteIntEx(pId, (void*)0x5909AB, 1);
	memsetEx(pId, (void*)0x5737E0, 0x75, 1);
	memcpyEx(pId, (void*)0x590AF0, (char*)"\xE9\x40\x01\x00\x00", 5);
	memcpyEx(pId, (void*)0x748E52 , (char*)"\x75\x12", 2);
	memsetEx(pId, (void*)0x590D7C, 0x90, 5);
	memsetEx(pId, (void*)0x590DB3, 0x90, 5);
	memcpyEx(pId, (void*)0x590D9F, (char*)"\xC3\x90\x90\x90\x90", 5);
}

PROCESS_INFORMATION CRunGame::runGame(LPSTR param)
{
	STARTUPINFOA cif;
	ZeroMemory( &cif, sizeof( STARTUPINFOA ) );
	PROCESS_INFORMATION pi;
	if(!CreateProcessA(gta_sa.toStdString().c_str(), param, NULL,NULL, FALSE, DETACHED_PROCESS | CREATE_SUSPENDED, NULL, NULL, &cif, &pi))
		MessageBoxA(NULL, "Failed to Create Process", "Error", MB_ICONERROR);
	return pi;
}

void CRunGame::reset()
{
	libs.clear();
	_winMode = false;
	size = "640*480";
	password = "";
	winTop = false;
}
