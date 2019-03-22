#include<iostream>
using namespace std;
typedef int digits;
typedef float fraction;
typedef double percentage;
digits count_no_of_digits(int num)
{
	int n=0;
	while (num > 0)
	{
		num = num / 10;
		n++;
	}
	return n;                                  //returns integer type
}
fraction return_fraction(int num1,int total)
{
	fraction res;
	res=((fraction)num1/total);
	return res;                             //returns float type
}
percentage calc_percentage(int num, int total)
{
	percentage p;
	p=(((percentage)num / total) * 100);
	return p;                                 //returns double type
}
int main()
{
	int num, total;
	cout << "Enter the number and total:" << endl;
	cin >> num >> total;
	digits count;
	count = count_no_of_digits(num);
	cout << "The no of digits in the number is:" << count << endl;
	fraction var;
	var = return_fraction(num, total);
	cout << "The fraction is:" << var << endl;
	percentage result;
	result = calc_percentage(num, total);
	cout << "The percentage is:" << result << endl;
	system("pause");
	return 0;
}