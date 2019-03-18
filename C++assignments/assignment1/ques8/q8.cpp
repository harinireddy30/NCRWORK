/*order of invocation of constructors and destructors*/
#include<iostream>
using namespace std;
class employee {
	char name;
	int salary;
public:
	employee(char c, int x)                                //parameterized constructor
	{
		name = c;
		salary = x;
		cout << "Constructor called" << endl;
	}
	~employee()                                           //destructor of employee class
	{
		cout << "Destructor called" << endl;
	}
};
void main()
{
	int x = 1;
	int y;
	employee e1('a', 100);  //constructor for object e1 called
	if (x > 0)
	{
		employee e2('b', 200); //constructor for object e2 called
	}                        //destructor for object e2 
	cin >> y;
}                            //destructor for object e1