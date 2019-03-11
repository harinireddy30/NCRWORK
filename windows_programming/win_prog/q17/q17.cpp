#include<Windows.h>
#include<iostream>
#include<stdio.h>
#include<tchar.h>
long x;
DWORD hThreadptr1;
DWORD hThreadptr2;
DWORD WINAPI Thread(LPVOID lparam)               //thread function
{
	x++;                                         //increments the value of x during thread execution
	return 1;
}
int main()
{
	STARTUPINFO si1, si2;
	PROCESS_INFORMATION pi1, pi2;
	HANDLE hThread1, hThread2;
	x = 0;
	printf("Initial value of x in primary thread is: %ld\n", x);
	hThread1 = CreateThread(NULL, 0, Thread, NULL, 0, &hThreadptr1);             //thread1 creation.increments x by 1
	if (hThread1 == NULL)
	{
		_tprintf("Thread creation unsuccessful.Error:(%d)\n", GetLastError());
		getchar();
		return 0;
	}
	_tprintf("Thread creation successful\n");
	hThread2 = CreateThread(NULL, 0, Thread, NULL, 0, &hThreadptr2);             //thread2 creation.increments x by 1 after thread1 gets signalled.
	if (hThread2 == NULL)
	{
		_tprintf("Thread creation unsuccessful.Error:(%d)\n", GetLastError());
		getchar();
		return 0;
	}
	_tprintf("Thread creation successful\n");
	WaitForSingleObject(hThread1, INFINITE);                 //wait till thread1 gets signalled
	_tprintf("Thread1-signalled\n");
	WaitForSingleObject(hThread2, INFINITE);                 //wait till thread2 gets signalled
	_tprintf("Thread2-signalled\n");
	if (x != 2)
		_tprintf("Inconsistent value\n");                   //to check for inconsistent value of x
	_tprintf("The value of x is:%ld", x);
	CloseHandle(hThread1);
	CloseHandle(hThread2);
	system("pause");
	return 0;
}
