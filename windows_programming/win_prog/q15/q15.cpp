/*CREATION OF SECONDARY THREAD WITHIN PRIMARY THREAD TERMINATE CODE*/
#include<Windows.h>
#include<iostream>
#include<stdio.h>
#include<tchar.h>
long x;
DWORD exitcode;
DWORD WINAPI sec_thread_func(LPVOID lparam)
{
	int i;
	for (i = 0; i < 20; i++)
		_tprintf("Thread is executing\n");
	Sleep(3000);
	printf("Thread execution completed\n");
	return 0;
}
int main()
{
	DWORD threadID;
	HANDLE hThread;
	DWORD exit_code;
	x = 0;
	printf("The value in primary thread is:%ld \n", x);
	hThread = CreateThread(NULL, 0, sec_thread_func, NULL, 0, &threadID);
	if (hThread == NULL)
	{
		printf("Thread not created.Error:(%d)", GetLastError());
		getchar();
		return 0;
	}
	else
		printf("Secondary thread created successfully\n");
	WaitForSingleObject(hThread, INFINITE);
	if (!GetExitCodeThread(hThread, &exit_code))
	{
		_tprintf("Retrieval of exit code failed.Error:(%d)", GetLastError());
		getchar();
		return 0;
	}
	else
	{
		_tprintf("Exit code is:(%d)", exit_code);
		_tprintf("Terminating the code..\n");
		TerminateThread(hThread,exit_code);
	}
	CloseHandle(hThread);
	printf("User input to exit\n");
	getchar();
	return 0;
}
