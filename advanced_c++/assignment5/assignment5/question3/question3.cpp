#include<iostream>
using namespace std;
class myclass {
	mutable int var1;
	const int var2;
public:
 /*	myclass(int x, int y)           
	{                            //constant members cant be modified..
		var1 = x;
		var2 = y;
	} */
	myclass(int x, int y) :var1(x), var2(y)
	{

	}
	void set_var1(int x)
	{
		var1 = x;
//		var2 = x;             //var2 is not mutable.So,cant be changed.
	}
	int get_var1()
	{
		return var1;
	}
	int get_var2()
	{
		return var2;
	}
};
int main()
{
	int x, y;
	cout << "Enter the values of var1 and var2 to pass to constructor" << endl;
	cin >> x >> y;
	myclass obj1(x,y);                     //set the values of var1 and var2
	obj1.set_var1(2);                      //change var1 to 2
	cout << "The values of var1 and var2 are:" << obj1.get_var1() << " " << obj1.get_var2() << endl;
	system("pause");
	return 0;
}