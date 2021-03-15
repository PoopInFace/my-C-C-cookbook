#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>

int main() {
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);
	HANDLE hSnp = INVALID_HANDLE_VALUE;
	hSnp = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	while (Process32Next(hSnp, &entry) == TRUE) {
		const WCHAR *procname;
		int procnamelen = MultiByteToWideChar(CP_ACP,0,entry.szExeFile,-1,NULL,0);
		procname = new WCHAR[procnamelen];
		MultiByteToWideChar(CP_ACP,0,entry.szExeFile,-1,(LPWSTR)procname,procnamelen);
		if (wcscmp(L"[System Process]",procname) == 1) {
			std::wcout << entry.szExeFile << std::endl;
		}	
	 }
}
