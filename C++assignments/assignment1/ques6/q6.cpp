/*distance between two points*/
#include<iostream>
using namespace std;
class point {
	int x;
	int y;
public:
	point(int a, int b)
	{
		x = a;
		y = b;
	}
	void displayp()
	{
		cout << "The point is:" << "(" << x << "," << y << ")" << endl;
	}
	void displayd()
	{
		cout << "The distance is :" << endl;
	}
	friend float distance(point &p, point &q);
};
void main()
{
	int a, b, g;
	float d;
	cin >> a >> b;
	point p1(a, b);
	cin >> a >> b;
	point p2(a, b);
	cout << "The point p1 is:" << endl;
	p1.displayp();
	cout << "The point p2 is:" << endl;
	p2.displayp();
	d = distance(p1, p2);
	cout << "The distance between the points is :" << d << endl;
	cin >> g;
}
float distance(point &p, point &q)
{
	float d;
	d = sqrtf((p.x - q.x)*(p.x - q.x) + (p.y - q.y)*(p.y - q.y));
	return d;
}