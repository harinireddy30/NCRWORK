/*Using scope resolution,use variables in newly created namespace*/


#include<iostream>

namespace CounterNamespace {
	int lowerbound;
	int upperbound;
	class counter {
		int count;
	public:
		counter(int x)
		{
			count = x;
		}
		int increaseCount()
		{
			count++;
			if (count > upperbound)          //return upperbound if value exceeds upperbound
				return upperbound;
			else return count;
		}
		int decreaseCount()                  //return lowerbound if value goes below lowerbound
		{
			count--;
			if (count < lowerbound)
				return lowerbound;
			else return count;
		}
	};
}
using namespace std;
int main()
{
	cout << "Enter the values of upper and lower bound" << endl;
	cin >> CounterNamespace::lowerbound >> CounterNamespace::upperbound;
	int initial_count;
	cout << "Enter initial value of count:" << endl;
	cin >> initial_count;
	CounterNamespace::counter count_obj1(initial_count);
	cout << "The values after incrementing are:" << endl;
	for (int i = 0; i < 10; i++)
		cout << count_obj1.increaseCount() << " ";
	cout << endl << "The values after decrementing are:" << endl;
	for (int i = 0; i < 10; i++)
		cout << count_obj1.decreaseCount() << " ";
	system("pause");
	return 0;
}