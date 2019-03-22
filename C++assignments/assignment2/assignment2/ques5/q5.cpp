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
	String(const char *p)       //(parameterized)
	{
		getchar();
		if (ptr != NULL)
			delete (ptr);
		size = strlen(p)+1;
		ptr = new char[size];
		strcpy(ptr, p);
	}
	String(const String &str)     //copy constructor
	{
		size = (str.size)+1;
		ptr = new char[size];     
		strcpy(ptr, str.ptr);         //deep copying
	}
	String operator=(String str)
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
		int i, j;
		temp.size = size + str.size+1;
		temp.ptr = new char[temp.size];
		for (i = 0; i < size; i++)
			temp.ptr[i] = ptr[i];
		for (j = 0; j < str.size; j++)
		{
			temp.ptr[i] = str.ptr[j];
			i++;
		}
		temp.ptr[i] = '\0';
		return temp;
	}
	~String()
	{
		delete(ptr);             //destructor
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
	char p[20];
	cin >> p;
	s.size = strlen(p);
	s.ptr = new char[s.size];
	strcpy(s.ptr, p);
	return cin;
}
int main()
{
	String s1, s2, s3, s4, s5;
	cout << "Enter string s1:" <<endl;
	cin >> s1;
	cout << s1;
	cout << "Enter string s2:" << endl;
	cin >> s2;
	cout << s2;
	char ch;
	ch = s1[1];                    // [] operator overloading
	cout << "The character at index 1 is:"<<ch<<"\n";
	s3 = s2;                       // = operator overloading
	cout << "String s3(copy of s2):"<<s3 <<"\n";
	s4 = s1 + s2;
	cout <<"String s4:"<< s4;
	s5 = String("apple");
	cout << "s5:" << s5<<"\n";
	String s6(s1);
	cout << "s6:" << s6 <<"\n";
	system("pause");
	return 0;
}
