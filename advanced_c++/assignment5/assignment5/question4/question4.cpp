#include<iostream>
using namespace std;
class MyClass {
	const int numA;
	const int numB;
public:
	MyClass(int x, int y) :numA(x), numB(y)
	{

	}
	int get_numA()
	{
		return numA;
	}
	int get_numB()
	{
		return numB;
	}
};
class MyClass_New {
	MyClass obj1;                   //creating an object of MyClass in MyClass_New
public:
	MyClass_New(int a, int b) :obj1(a,b) {

	}
	int get_a()
	{
		return obj1.get_numA();
	}
	int get_b()
	{
		return obj1.get_numB();
	}
};
int main()
{
	cout << "Enter the values to pass to members of Myclass:" << endl;
	int value1, value2;
	cin >> value1 >> value2;
	MyClass_New obj2(value1, value2);
	cout << "The values set to members of MyClass are:" << obj2.get_a() << " " << obj2.get_b() << endl;
	system("pause");
	return 0;
}