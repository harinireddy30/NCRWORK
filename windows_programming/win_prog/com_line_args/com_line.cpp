/*Command line Arguments*/

#include <windows.h>
#include <stdio.h>
#include <shellapi.h>
int main()
{
	LPWSTR *szArglist; //long pointer to argument list
	int no_of_args;
	int i;

	szArglist = CommandLineToArgvW(GetCommandLineW(), &no_of_args);  //parses a unicode command line string and returns an array of pointers to command line
	if (NULL == szArglist)
	{
		printf("CommandLineToArgvW failed with error %d\n",GetLastError()); //printf the last error in case of failure
	}
	else 
		for (i = 0; i < no_of_args; i++) 
		printf("%d> %S\n", i, szArglist[i]);          //print all the arguments passed
	system("pause");
	return 0;
}