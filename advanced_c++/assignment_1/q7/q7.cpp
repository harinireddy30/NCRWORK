#include<iostream>
using namespace std;
class polygon {
           int dimension1;
	       int dimension2;
public:
	polygon()
	{

	}
	polygon(int width,int height)
	{
		dimension1 = width;
		dimension2 = height;
	}
	void set_value(int width, int height)
	{
		dimension1 = width;
		dimension2 = height;
	}
	int get_dimension1()
	{
		return dimension1;
	}
	int get_dimension2()
	{
		return dimension2;
	}
};
class rectangle :public polygon {
public:
	rectangle()
	{
		
	}
	rectangle(int i, int j) :polygon(i, j)
	{
		

	}
	void calculate_area()
	{
		cout << "Area is:" << (i*j) << endl;
	}
};
int main()
{
	rectangle r1;
	r1.set_value(2, 3);
	r1.calculate_area();
	system("pause");
}
