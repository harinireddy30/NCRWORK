#include<iostream>
using namespace std;
class shape {
	char color[10];
public:
	void get_color()
	{
		cout << "enter the colour:" << endl;
		cin >> color;
	}
	void get_dimensions()
	{
		cout << "Shape isn't given yet" << endl;
	}
	void display_area()
	{
		cout << "Area yet to be decided depending on the shape" << endl;
	}
	void print_color()
	{
		cout << "color is:" << color << endl;
	}
};
class triangle :public shape{
	int base, height;
public:
	void get_dimensions()
	{
		cout << "Enter dimensions of triangle:" << endl;
		cin >> base>>height;
	}
	void display_area()
	{
		cout << "Area of triangle:" << (0.5*base*height) << endl;
	}
};
class rectangle:public shape{
	int length, breadth;
public:
	void get_dimensions()
	{
		cout << "Enter dimensions of rectangle:" << endl;
		cin >> length >> breadth;
	}
	void display_area()
	{
		cout << "Area of rectangle:" << (length*breadth) << endl;
	}
};
class square :public shape {
	int side;
public:
	void get_dimensions()
	{
		cout << "Enter dimensions of square:" << endl;
		cin >> side;
	}
	void display_area()
	{
		cout << "Area of square:" << (side*side) << endl;
	}
};
int main()
{
	shape s;
	triangle t1;
	square s1;
	rectangle r1;
	s.get_color();
	s.get_dimensions();
	s1.get_dimensions();
	t1.get_dimensions();
	r1.get_dimensions();
	t1.display_area();
	r1.display_area();
	s1.display_area();
	s.display_area();
	system("pause");
	return 0;
}