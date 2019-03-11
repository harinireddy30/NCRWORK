/*Implementation of some ANSI funstions*/
#include <iostream>
#include<Windows.h>
int main()
{
	CHAR arr1[] = "harini";                        //ANSI ARRAY
	WCHAR arr2[] = L"harini1234";                  //UNICODE ARRAY
	PCHAR new_array;                               //pointer to character array
	PWCHAR new1_array;                             //pointer to wide character array 
	if (IsTextUnicode(arr1, strlen(arr1), NULL))   //checking if arr1 is unicode char array
		printf("ARRAY arr1 is UNICODE \n");
	else
		printf("ARRAY arr1 is NOT A UNICODE \n");
	if (IsTextUnicode(arr2, wcslen(arr2), NULL))   //checking if arr2 is unicode char array
		printf("ARRAY arr2 is UNICODE \n");
	else
		printf("ARRAY arr2 is NOT A UNICODE \n");

	/*MULTIBYTE TO WIDECHAR CONVERSION*/
	int x=MultiByteToWideChar(CP_UTF8,0, arr1, -1,NULL, 0);        //returns size of arr1 
	if (0 == x)
		printf("System terminated with error (%d)\n",GetLastError());    //if value of x is zero,displays error
	else
		printf("Size is %d\n", x);
	new1_array = new WCHAR[x];                                    //allocating memory of x bytes of wchar type
	int y= MultiByteToWideChar(CP_UTF8, 0, arr1, -1,new1_array, x);    //conversion of mutlibyte to wide char,store in new1_array
	if (0 == y)
		printf("System terminated with error\n");
	else
	{
		printf("Converted succesfully\n");
		printf("%S\n", new1_array);
	}

	/*WIDECHARTOMULTIBYTE CONVERSION*/
	int z = WideCharToMultiByte(CP_UTF8, 0, arr2, -1, NULL, 0,NULL,NULL);
	if (0 == z)
		printf("Terminated with error %d", GetLastError());
	else
		printf("Size is %d\n", z);
	new_array = new CHAR[z];
	int w = WideCharToMultiByte(CP_UTF8, 0, arr2, -1,new_array, z, NULL, NULL);
	if (0 == w)
		printf("System terminated with error\n");
	else
	{
		printf("Converted succesfully\n");
		printf("%s\n", new_array);
	}
	system("pause");
	return 0;
}