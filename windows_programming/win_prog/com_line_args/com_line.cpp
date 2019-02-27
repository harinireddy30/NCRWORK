/*Command line Arguments*/

#include<Windows.h>
#include <stdio.h>
#include <shellapi.h>          
int main()
{
	LPWSTR *arglist; //long pointer to argument list
	int no_of_args;
	int i;

	arglist = CommandLineToArgvW(GetCommandLineW(), &no_of_args);  //parses a unicode command line string and returns an array of pointers to command line
	if (NULL == arglist)
	{
		printf("CommandLineToArgvW failed with error %d\n",GetLastError()); //printf the last error in case of failure
	}
	else 
		for (i = 0; i < no_of_args; i++) 
		printf("%d> %S\n", i, arglist[i]);          //print all the arguments passed

	TCHAR buff[32767],buff1[32767];
	int buff_count, buff_count1;
	buff_count = ExpandEnvironmentStrings("%PATH%", buff, 32767);  //environment variable path
	buff_count1 = ExpandEnvironmentStrings("%TEMP%", buff1, 32767); //environment variable temp
	if (buff_count > 32767)
		printf("Buffer size of destination is greater than source\n");
	else
	{
		wprintf(L"%S\n\n", buff);
		wprintf(L"%S", buff1);
	}
	system("pause");
	return 0;
}