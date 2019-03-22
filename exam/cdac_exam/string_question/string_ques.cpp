/*define mystring class with 
  1)char *name and int len as data elements
  2)default,copy and parameterized constructors with deep copying
  3)define destructor,overload all symbols:+,<<,>>,=,[].
  4)include a friend function to mystring class which takes an array of objects of mystring class and
  sort them in ascending order using bubble sort.*/

#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<iostream>
using namespace std;
class mystring {
	char *name;
	int len;
public:
	mystring()                    //default constructor
	{
		name = NULL;
		len = 0;
	}
	mystring(const char*p)     //parameterized constructor
	{
		len = strlen(p) ;
		name = new char[len+1];
		strcpy(name, p);             //deep copying
	}
	mystring(const mystring &temp)       //copy constructor
	{
		len = temp.len;
		name = new char[len+1];
		strcpy(name,temp.name);       //deep copying
	}
	char operator[](int index)          //overloading of [] operator
	{
		if (index > len)
			cout << "Index number greater than length of the string" << endl;
		else
		{
			return name[index];
		}
	}
	mystring operator=(mystring str)       //overloading of = operator 
	{
		len = str.len;
		name = new char[len + 1];
		strcpy(name, str.name);
		return (*this);
	}
	mystring operator+(mystring str)       //overloading of + operator
	{
		mystring temp;
		temp.len = len + str.len + 1;
		int i, j;
		for (i = 0; i < len; i++)
			temp.name[i] = name[i];
		for (j = 0; j < str.len; j++)
		{
			temp.name[i] = str.name[j];
			i++;
		}
		temp.name[i] = '\0';
		return temp;
	} 
	friend istream &operator>>(istream& cin, mystring &str);    //friend function for overloading of >> operator
	friend ostream &operator<<(ostream& cout, mystring str);    //friend function for overloading of << operator
	friend void sort(mystring str[], int size);                 //friend function to sort objects of mystring class
	~mystring()                                                //destructor
	{
		if (name != NULL)
			delete name;
	}
};
istream &operator>>(istream& cin, mystring &str)               //overloading of >> operator
{
	int i = 0;
	while (str.name[i] != '\0')
		cin >> str.name[i];
	return cin;
}
ostream &operator<<(ostream& cout, mystring str)              //overloading of <<operator
{
	int i = 0;
	if (str.name == NULL)
	 cout << "Empty string" << endl;
	else
	{
		while (str.name[i] != '\0')
		{
			cout << str.name[i];
			i++;
		}
	}
	return cout;
}
void sort(mystring str[], int size)                                      //bubble sorting of mystring objects
{
	int i, j;
	char *p;
	for (i = 0; i < (size - 1); i++)
	{
		for (j = i; j < (size - 1); j++)
		{
			int x = strcmp(str[i + 1].name, str[i].name);
			if (x < 0)
			{
				p = str[i].name;
				str[i].name = str[i + 1].name;
				str[i].name = p;
			}
		}
	}
}
int main()
{
	mystring s1("the");
	cout <<"String s1:"<< s1;
	mystring s2("bird");
	cout <<endl<<"String s2:"<< s2;
	char x=s2[1];
	cout << "character at index 1 is:" << x << endl;
	mystring s3 = s1;
	cout << "String s3 using copy constructor(s3=s1) is:"<<s3 << endl;
	mystring s4;
//	s4 = s1 + s2;
	cout << "String s4 is:" << s4 << endl;
	system("pause");
	return 0;
}