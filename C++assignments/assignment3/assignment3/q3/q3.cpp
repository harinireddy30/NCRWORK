#include<iostream>
using namespace std;
class shape {
	char color[10];                      //data members of class shape
public:
	void get_color()
	{
		cout << "enter the colour:" << endl;          //member function to input colour of shape class
		cin >> color;
	}
	void get_dimensions()                             //member function to input dimensions of shape class
	{
		cout << "Shape isn't given yet" << endl;
	}
	void display_area()                               //member function to display the area of shape class
	{
		cout << "Area yet to be decided depending on the shape" << endl;   //as class is generic
	}
	void print_color()                                //to print the color of class
	{
		cout << "color is:" << color << endl;
	}
};
class triangle :public shape{                         //derived class from shape class(public mode)
	int base, height;                                  //member functions of triangle class
public:
	void get_dimensions()                               //get dimensions of triangle class
	{
		cout << "Enter dimensions of triangle:" << endl;
		cin >> base>>height;
	}
	void display_area()                                    //display the area of triangle
	{
		cout << "Area of triangle:" << (0.5*base*height) << endl;
	}
};
class rectangle:public shape{                           //derived class from shape class(public mode)
	int length, breadth;                                //member functions of rectangle class
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
	shape s;                   //object s of shape class
	triangle t1;               //objects of triangle,square and rectangle
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