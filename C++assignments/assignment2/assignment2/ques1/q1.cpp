/*Define string class with dynamic memory allocation for string. Define default
constructor, parameterized constructors, copy constructor, destructor, Overload +,
[], =, <<, >> operators. Observe the behavior of shallow copying and deep copying.*/

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
	String(char *p)       //shallow copying (parameterized)
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
		delete(ptr);             //destructor
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
		String temp; int i, j;
		temp.size = size + str.size;
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
	friend ostream & operator<< (ostream &cout, String s);
	friend istream & operator>>(istream &cin, String &s);
};
ostream & operator<< (ostream &cout, String s)
{
	for (int i = 0; i < s.size; i++)
		cout << s[i];
	cout << endl;
}
istream & operator>>(istream &cin, String &s)
{
	char *p;
	cin >> p;
	s.size = strlen(p);
	s.ptr = new char[s.size];
	strcpy(s.ptr, p);
	return cin;
}
int main()
{
	char string1[30];
	cin >> string1;
	String s1, s2(string1), s3(s2);
	String s4 = s2 + s3;
	String s5 = s3;
	cout << "s1:" << s1 << " " << "s2:" << s2 << endl;
	cout << "s3:" << s3 << " " << "s4:" << s4 << " " << "s5:" << s5 << endl;
	system("pause");
	return 0;
}
