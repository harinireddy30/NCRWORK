/*CREATION OF SECONDARY THREAD WITHIN PRIMARY THREAD TERMINATE CODE*/
#include<Windows.h>
#include<iostream>
#include<stdio.h>
#include<tchar.h>
long x;
DWORD exitcode;
DWORD WINAPI sec_thread_func(LPVOID lparam)                     //secondary thread function
{
	int i;
	x++;                                                        //increment the value of x in secondary thread
	for (i = 0; i < 20; i++)
		_tprintf("Thread is executing\n");                     //prints until thread terminates execution
	Sleep(3000);                                               //sleep for 3 seconds
	printf("Thread execution completed\n");
	return 0;
}
int main()
{
	DWORD threadID;
	HANDLE hThread;
	DWORD exit_code;
	x = 0;                                                     //initial value of x is set to zero
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
	WaitForSingleObject(hThread, INFINITE);                      //wait for thread to terminate on its own
	if (!GetExitCodeThread(hThread, &exit_code))                 //generates exit code
	{
		_tprintf("Retrieval of exit code failed.Error:(%d)", GetLastError());
		getchar();
		return 0;
	}
	else
	{
		_tprintf("Exit code is:(%d)", exit_code);                //print the exit code
		_tprintf("Terminating the code..\n");
		TerminateThread(hThread,exit_code);                      //terminates the thread
	}
	printf("The value of x after secondary thread execution is %ld\n", x);    //checking the value of x after termination of secondary thread
	CloseHandle(hThread);                                                     //close the handle to thread
	printf("User input to exit\n");
	getchar();
	return 0;
