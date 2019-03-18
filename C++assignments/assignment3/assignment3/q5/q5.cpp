#include<iostream>
using namespace std;
class person
{
public:
	char *name;
	int age;
	person(int name_size,int x)
	{
		name = new char[x];
		cin >> name;
		age = x;
	}
	void display()
	{
		cout <<"NAME:"<< name << "Age:" << age << endl;
	}
};
class physique : virtual public person
{
public:
	int height;
	int weight;
	physique()
	{
		height = 10;
		weight = 50;
	}
	void displayp()
	{
		//displayn();
		cout << "the person height and weight are " << height << " " << weight << endl;
	}
};
class family : virtual public person
{
public://public section
	int numChildren;
	string religion;
	family()
	{
		numChildren = 2;
		religion = "hindu";
	}
	void displayf()
	{

		cout << "the number of children are " << numChildren << " and religion is " << religion << endl;
	}
};
class employee : public physique, public family
{
public://public section
	int emno;
	float salary;
	employee()
	{
		emno = 31;
		salary = 70000.0f;
	}
	void display()
	{
		display();
		displayp();
		displayf();
		cout << "the employee number is " << emno << " salary is " << salary << endl;
	}
};
int main()
{
	employee obj1;
	// calling employee display function
	obj1.display();
	// to stop console from closing
	system("pause");
	return 0;
}