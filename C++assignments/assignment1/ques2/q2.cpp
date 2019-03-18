#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;
class student {
	char *studentname;
	char grade;
	int marks1;
	int marks2;
	int marks3;
public:
	void setdata(char *n)
	{
		studentname = (char *)malloc((sizeof(char)*(strlen(n) + 1)));     //assigning pointer to dyhnamically allocated memory
		strcpy(studentname, n);                                           //byte copying 
		cout << "Enter the marks of students" << endl;
		cin >> marks1;
		cin >> marks2;
		cin >> marks3;
	}
	void display()
	{
		cout << "student name=" << studentname << " " << "marks:" << marks1 << " " << marks2 << " " << marks3 << endl;
	}
	int cal_avg()
	{
		int avg;
		avg = ((marks1 + marks2 + marks3) / 3);
		return avg;
	}
	void compute_grade(int x)
	{
		if (x >= 60)
			cout << "First class" << endl;
		else if (49 < x && x < 60)
			cout << "Second class" << endl;
		else if (39 < x && x < 50)
			cout << "Third class" << endl;
		else if (0 <= x && x < 40)
			cout << "Failed" << endl;
		else
			cout << "Enter valid marks";
	}
};
void main()
{
	int x, y;
	student s1;
	char n[20];                                          //character array for name
	cout << "Enter the student_name" << endl;
	cin >> n;                                            //input name string
	s1.setdata(n);
	x = s1.cal_avg();
	s1.display();
	s1.compute_grade(x);
	cin >> y;
}