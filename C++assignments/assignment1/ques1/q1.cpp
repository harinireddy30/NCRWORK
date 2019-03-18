#include<iostream>
using namespace std;
class time {
	int hours;
	int minutes;
	int seconds;
public:
	time()
	{
		hours = minutes = seconds = 0;
	}
	time(int h, int m, int s)
	{
		hours = h;
		minutes = m;
		seconds = s;
	}
	void display()
	{
		cout << hours << ":" << minutes << ":" << seconds << ":" << endl;
	}
	void add_time(time t1, time t2)
	{
		hours = t1.hours + t2.hours;
		minutes = t1.minutes + t2.minutes;
		seconds = t1.seconds + t2.seconds;
		if (hours > 23)
			hours = hours - 24;
		if (minutes > 59)
		{
			minutes = minutes - 60;
			hours = hours + 1;
		}
		if (seconds > 59)
		{
			seconds = seconds - 60;
			minutes = minutes + 1;
		}
	}
};
int main()
{
	int a;
	time t1, t2, t3;
	t1 = time(23, 5, 59);
	t2 = time(2, 3, 4);
	t1.display();
	t2.display();
	t3.add_time(t1, t2);
	t3.display();
	cin >> a;
}