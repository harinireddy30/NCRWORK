#include<iostream>
using namespace std;
class distance2;                         //class definition of distance2
class distance1 {
	float metres;
	float centimetres;
public:
	distance1()
	{
		metres = centimetres = 0;
	}
	distance1(float d)
	{
		metres = d;
		centimetres = d * 100;
	}
	void display1()
	{
		cout << "The distance in metres is: " << metres << endl;
	}
	friend distance1 add_distance(distance1 &d1, distance2 &d2);
};
class distance2 {
	float feet;
	float inches;
public:
	distance2()
	{
		feet = inches = 0;
	}
	distance2(int f)
	{
		feet = f;
		inches = f * 12;
	}
	void display2()
	{
		cout << "The distance in feet is: " << feet << endl;
	}
	friend distance1 add_distance(distance1 &d1, distance2 &d2);
};
distance1 add_distance(distance1 &d1, distance2 &d2);
void main()
{
	int x;
	distance1 d1(2);
	d1.display1();
	distance2 d2(1);
	d2.display2();
	distance1 d3;
	d3 = add_distance(d1, d2);                               //result is of type distance1
	cout << "The sum of the objects is: " << endl;
	d3.display1();
	cin >> x;
}
distance1 add_distance(distance1 &d1, distance2 &d2)
{
	distance1 temp;
	temp.centimetres = (d1.metres) * 100 + d2.feet * 12 * 2.54;  //conversion into metres
	temp.metres = temp.centimetres / 100;
	return temp;
}