/*CREATING AN EVENT*/
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<tchar.h>
int main()
{
	HANDLE g_hEvent = CreateEvent(NULL, FALSE, FALSE, TEXT("xyz"));    //g_hEvent is a handle to the event created
	getchar();
	return 1;
}