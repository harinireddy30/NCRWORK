#include<Windows.h>
#include<iostream>
#include<tchar.h>
constexpr auto BUFFSIZE=32767;
int _tmain(int argc, LPTSTR argv[])
{
	HANDLE hfile;
	TCHAR buff[BUFFSIZE];
	hfile = CreateFile(argv[1], GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hfile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("File doesnt exist.Error: %d", GetLastError()));
		getchar();
		return FALSE;
	}
	else
	{
		DWORD &nbr;
		ZeroMemory(buffer, BUFFSIZE);
	}
}