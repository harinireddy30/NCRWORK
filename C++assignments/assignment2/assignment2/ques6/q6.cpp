#include<iostream>
using namespace std;
class polar {
	int r;
	int angle;
	static int count;              //declaring count as a static variable
public:
	polar()
	{
		r = angle = 0;             //default constructor
	}
	polar(int x, int y)
	{
		r = x;
		angle = y;                 //parameterized constructor
	}
	static int get_count()
	{
		return count;              //function to return count value
	}
	static void inc_count()
	{
		++count;                   //function to increment count each time an object is created
	}
};
int polar::count;                  //static members must be defined outside class using scope resolution
void main()
{
	int y;
	polar p1, p2;
	p1 = polar();
	p1.inc_count();                //increment count after creating object 1
	p2 = polar(1, 2);
	p2.inc_count();                //increment count after creating object 2
	cout << polar::get_count() << endl;    //display count value(object isnt required for calling static member functions) 
	cin >> y;
}
