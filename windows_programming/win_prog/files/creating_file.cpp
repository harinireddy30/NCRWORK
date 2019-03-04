/*READING AND WRITING TO A FILE*/
#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<iostream>
#include<tchar.h>
int _tmain(int argc, LPTSTR argv[])
{
	      
	char *ch;                              
	int n;
	printf("Enter the size of buffer\n");
	scanf("%d", &n);
	ch = new char[n];                              //buffer to store elements after reading from a file
	char ch1[] = "abcd";
	HANDLE hfile;         //file handler
	DWORD i, k;           //no of bytes read or written
	ZeroMemory(ch,100);   //clearing the contents of character buffer
	hfile = CreateFile(("file1.txt"), GENERIC_READ|GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL); //creating a file with file handler
	BOOL r1 = ReadFile(hfile, ch, 10, &i, NULL);        //reading a file
	if (TRUE == r1)                                     //returns a nonzero value in case of success
	{
		printf("The file is created\n");
			for (int j = 0; j < 10; j++)              
		    printf("%c ", ch[j]);                       //printing the read values of a file
	}
	else
		printf("The file cant be opened.Error:(%d)", GetLastError());
	BOOL w1 = WriteFile(hfile, ch1, 3, &k, NULL);
	if (TRUE == w1)
	{
		printf("\nContents of buffer ch1 are written to file\n");
	}
	else
		printf("The file cant be opened.Error=(%d)\n",GetLastError());
	CloseHandle(hfile);
	system("pause");
}