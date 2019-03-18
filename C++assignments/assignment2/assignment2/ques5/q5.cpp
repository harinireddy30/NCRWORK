/*Define string class with dynamic memory allocation for string. Define default
constructor, parameterized constructors, copy constructor, destructor, Overload +,
[], =, <<, >> operators. Observe the behavior of shallow copying and deep copying.*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;
class String {
	char *ptr;
	int size;
public:
	String()
	{
		ptr = NULL;       //default constructor
		size = 0;
	}
	String(const char *p)       //shallow copying (parameterized)
	{
		size = strlen(p);
		ptr = new char[size];
		strcpy(ptr, p);

	}
	String(const String &str)     //copy constructor
	{
		size = str.size;
		ptr = new char[str.size];     //deep copying
		strcpy(ptr, str.ptr);
	}
	~String()
	{
		if (ptr != NULL)             //destructor
			free(ptr);
	}
	String operator=(String &str)
	{
		if (ptr != NULL)
			free(ptr);
		size = str.size;
		ptr = new char[str.size];
		strcpy(ptr, str.ptr);
		return (*this);
	}

	char operator[](int index)
	{
		if (index > size)
			cout << "index is greater than size" << endl;
		else
		{
			return ptr[index];
		}
	}
	String operator+(String &str)
	{
		String temp;
		temp.size = size + str.size;
		temp.ptr = new char[temp.size];
		strcpy(temp.ptr, ptr);
		strcpy(temp.ptr, str.ptr);
		return temp;
	}
	friend ostream & operator<< (ostream &cout, String s);
	friend istream & operator>>(istream &cin, String &s);
};
ostream & operator<< (ostream &cout, String s)
{
	for (int i = 0; i < s.size; i++)
		cout << s[i];
	cout << endl;
	return cout;
}
istream & operator>>(istream &cin, String &s)
{
	char p[50];
	cin >> p;
	s.size = strlen(p);
	s.ptr = new char[s.size];
	strcpy(s.ptr, p);
	return cin;
}
void main()
{
	String s1, s2("def");
//	cout << "Enter the string s1:" << endl;
//	cin >> s1;
	cout << s1;
	cout << s2;
	system("pause");
}
