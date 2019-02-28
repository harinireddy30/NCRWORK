#include <windows.h>
#include<iostream>
#include <stdio.h>
#include <tchar.h>
int _tmain(int argc, TCHAR *argv[])
{
	STARTUPINFO si, si1;
	PROCESS_INFORMATION pi,pi1;
	ZeroMemory(&si, sizeof(si));
	ZeroMemory(&si1, sizeof(si1));
	std::cout << argc;
	if (argc != 3)
	{
		printf("Usage: %s [notepad]\n", argv[0]);
		getchar();
		return 1;
	}
	if (!CreateProcess(NULL,argv[1],NULL,NULL,FALSE,0,NULL,NULL,&si,&pi))    //creation of child process
	{
		printf("CreateProcess failed (%d).\n", GetLastError());
		getchar();
		return 1;
	}
	printf("Handle of process is %ld\n", (pi.hProcess));     //handle ID
	printf("Process ID: %ld\n", pi.dwProcessId);             //process ID
	printf("Thread ID:%ld\n", pi.dwThreadId);                //thread ID
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	WaitForSingleObject(pi.hProcess, 5000);
	ZeroMemory(&pi, sizeof(pi));
	ZeroMemory(&pi1, sizeof(pi1));
	if (!CreateProcess(NULL, argv[2], NULL, NULL, FALSE, 0, NULL, NULL, &si1, &pi))    //creation of child process
	{
		printf("CreateProcess failed (%d).\n", GetLastError());
		getchar();
		return 1;
	}
	printf("Handle of process is %ld\n", (pi1.hProcess));     //handle ID
	printf("Process ID: %ld\n", pi1.dwProcessId);             //process ID
	printf("Thread ID:%ld\n", pi1.dwThreadId);                //thread ID
	WaitForSingleObject(pi1.hProcess, INFINITE);
		CloseHandle(pi1.hProcess);
		CloseHandle(pi1.hThread);
	system("pause");
	return 1;
}