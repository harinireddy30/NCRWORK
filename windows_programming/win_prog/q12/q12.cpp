/*CREATION OF THREAD USING CreateThread API*/

#include<Windows.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
DWORD WINAPI ThreadFunction(LPVOID lparam)
{
	printf("Creation of child thread\n");
	return 0;
}
int main()
{
	DWORD threadid;
	HANDLE hthread;
	hthread = CreateThread(NULL, 0, ThreadFunction, NULL, 0, &threadid);    //creates a thread
	if (hthread == NULL)     
	{
		printf("Thread not created.Error:(%d)\n", GetLastError());
		getchar();
		return 0;
	}
	CloseHandle(hthread);
	system("pause");
	return 0;
}
