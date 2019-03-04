#include<iostream>
using namespace std;
template<class T>
int linear_search(T ele, T arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		if (arr[i] == ele)
			return i;
	return 0;
}
class complex {
	int real, imag;
public:
	complex()
	{
		real = imag = 0;
	}
	complex(int x)
	{
		real = imag = 0;
	}
	complex(int x, int y)
	{
		real = x;
		imag = y; 
	}
	complex(const complex &a)
	{
		real = a.real;
		imag = a.imag;
	}
	int operator==(complex b)
	{
		if (real == b.real&&imag == b.imag)
			return 1;
		else
			return 0;
	}
	friend istream& operator>>(istream& input, complex a);
	~complex()
	{
		cout << "Destructor called" << endl;
	}
};
istream& operator>>(istream& input, complex a)
{
	input >> a.real >> a.imag;
	return input;
}
int linear_search(const char *arr[], int size, char x[20])                //for string type data
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(arr[i], x) == 0)
			return i;
	}
	return -1;
}
int main()
{
	int *arr_int, sizei, ele;
	cout << "enter the size of array:" << endl;
	cin >> sizei;
	arr_int = new int[sizei];
	cout << "Enter the elements in the list" << endl;
	for (int i = 0; i < sizei; i++)
		cin >> arr_int[i];
	cout << "Enter the element to search" << endl;
	cin >> ele;
	int pos1 = linear_search(ele,arr_int, sizei);
	if (pos1 == 0)
	{
		cout<<"Element not found"<<endl;
	}
	else
	{
		cout << "Element found at " << pos1 << endl;
	}
	float *arr_float, elef;
	int sizef;
	cout << "enter the size of array:" << endl;
	cin >> sizef;
	arr_float = new float[sizef];
	cout << "Enter the elements in the list" << endl;
	for (int i = 0; i < sizef; i++)
		cin >> arr_float[i];
	cout << "Enter the element to search" << endl;
	cin >> elef;
	int pos2 = linear_search(elef, arr_float, sizef);
	if (pos2 == 0)
	{
		cout << "Element not found\n";
	}
	else
	{
		cout << "Element found at " << pos2 << endl;
	}
	double *arr_double, eled;
	int sized;
	cout << "enter the size of array:" << endl;
	cin >> sized;
	arr_double = new double[sized];
	cout << "Enter the elements in the list" << endl;
	for (int i = 0; i < sized; i++)
		cin >> arr_double[i];
	cout << "Enter the element to search" << endl;
	cin >> eled;
	int pos3 = linear_search(eled,arr_double,sized);
	if (pos3 == 0)
	{
		cout << "Element not found\n";
	}
	else
	{
		cout << "Element found at " << pos3 << endl;
	}
	const char *arr[] = { "abcd","defg","hijk","lmno","pqrs" };
	char str[] = "lmno";
	int pos4 = linear_search(arr, 4, str);
	if (pos4 == 0)
	{
		cout << "Element not found\n";
	}
	else
	{
		cout << "Element found at " << pos4 << endl;
	}
	complex c[6];
	complex c1(1, 2);
	for (int i = 0; i < 6; i++)
		cin >> c[i];
	cout << "enter the complex objects \n";
	int pos5 = linear_search(c1,c,6);
	if (pos5 == -1)
	{
		cout << "Element not found\n";
	}
	else
	{
		cout << "Element found at position:" << pos5 << endl;
	}
	system("pause");
	return 0;
}
