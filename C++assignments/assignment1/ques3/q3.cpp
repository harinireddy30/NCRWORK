/*Write a C++ program to add two complex numbers. The class Complex contains
three constructors.
a. One with no parameter.
b. With one parameter(Same value for real and imaginary part)
c. With two parameters.
d. Two friend functions
   i. One to add two complex number by taking two reference variables of
   the class complex.
   ii. One to multipy two complex number by taking two reference
   variables of class complex*/

#include<iostream>
using namespace std;
class complex {
	float real;
	float img;
public:
	complex()            
	{
		real = img = 0;
	}
	complex(float x)
	{
		real = img = x;
		if (!isdigit(x))
		{

		}
	}
	complex(float x, float y)
	{
		real = x;
		img = y;
	}
	void display()
	{
		cout << "real=" << real <<" "<< "img=" << img <<endl;
		if (real == 0)
		cout << img << "i" << endl;
		else if (img == 0)
			cout << real << endl;
		else if (img > 0)
			cout << real << "+" << img << "i" << endl;
		else if (img < 0)
			cout << real << "-" << -img << "i" << endl;
	}
	friend complex add_complex(complex &a, complex &b);   //declaration of friend functions to perform addition n multiplication
	friend complex mul_complex(complex &a, complex &b);   
};
complex add_complex(complex &a, complex &b);
complex mul_complex(complex &a, complex &b);
int main()
{
	float c1_real, c1_img,c2_real, c2_img;
	complex sumof_c1_c2,mulof_c1_c2;
	cout << "Enter the parameter to be passed to c1:";
	cin >> c1_real>> c1_img;

	complex c1(c1_real,c1_img);
	cout << endl<<"Enter real and imaginary values of c2:";
	cin >> c2_real >> c2_img;

	complex c2(c2_real,c2_img);

	cout <<endl<< "complex c1:";
	c1.display();
	cout << "complex c2:";
	c2.display();

	sumof_c1_c2 = add_complex(c1, c2);
	mulof_c1_c2 = mul_complex(c1, c2);
	cout << "The sum of c1 and c2 is :" << endl;
	sumof_c1_c2.display();
	cout << "The product of c1 and c2 is :" << endl;
	mulof_c1_c2.display();
	system("pause");
	return 0;
}
complex add_complex(complex &a, complex &b)
{
 	complex temp;
	temp.real = a.real + b.real;
	temp.img = a.img + b.img;
	return temp;
}
complex mul_complex(complex &a, complex &b)
{
	complex temp;
	temp.real = (a.real*b.real) - (a.img*b.img);
	temp.img = (a.real*b.img) + (a.img*b.real);
	return temp;
}