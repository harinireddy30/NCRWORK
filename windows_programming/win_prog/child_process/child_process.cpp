/*CHILD PROCESS*/
#include <windows.h>
#include<iostream>
#include <stdio.h>
#include <tchar.h>
int _tmain(int argc, TCHAR *argv[])
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	if (argc != 2)
	{
		printf("Usage: %s [notepad]\n", argv[0]);
		getchar();
		return 1;
	}
	if (!CreateProcess(NULL, argv[1], NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))    //creation of child process
	{
		printf("CreateProcess failed (%d).\n", GetLastError());
		getchar();
		return 1;
	}
	else
	printf("Current process ID is: %ld", GetCurrentProcessId());                      //prints the process ID of current process 
	printf("\nCUrrent thread ID is: %ld", GetCurrentThreadId());                      //prints the thread ID of current thread
	printf("\nProcess ID of pi is: %ld", GetProcessId(pi.hProcess));                  //prints the process ID of a particular process
	printf("\nThread ID of pi is: %ld", GetThreadId(pi.hThread));                     //prints the thread ID of a particulat thread
	printf("\nProcess ID of thread is: %ld", GetProcessIdOfThread(pi.hThread));       
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	system("\npause");
	return 0;
}
