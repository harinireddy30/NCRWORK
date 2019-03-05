#include<Windows.h>
#include<iostream>
#include<stdio.h>
DWORD WINAPI ThreadFunc(LPVOID lparam)        //function for printing 1 to 1000
{
	int i;
	for (i = 1; i < 1001; i++)
	{
		printf("%d\n",i);
		Sleep(10);                           //waits for 0.01 sec(10 msec) before printing the next number
	}
	return 0;
}
int main()
{
	DWORD thrdID;
	HANDLE hThread;
	hThread=CreateThread(NULL, 0, ThreadFunc, NULL, CREATE_SUSPENDED, &thrdID);    //creation of thread in suspended state
	if (hThread == NULL)
	{
		printf("Thread isn't created.Error(%d)\n", GetLastError());
		getchar();
		return 1;
	}
	Sleep(5000);                                                                   //waits for 5 sec after creation of thread
	ResumeThread(hThread);                                                         //start printing 
	CloseHandle(hThread);
	printf("Waiting for user's input\n");                                           //user input req to exit
	getchar();
	return 0;
}
