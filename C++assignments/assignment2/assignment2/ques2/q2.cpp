#include<iostream>
#include<string>
using namespace std;
class student
{
	char name[10];
	int roll_no;
	int marks1;
	int marks2;
	int marks3;
	int total;
	char grade;
public:
	friend void generate_results(student *s, int n);               //to generate total and grade
	friend istream & operator>>(istream &input, student &s);       //input and output operator overloading for student class
	friend ostream & operator<<(ostream &output, student s);
};
istream& operator>>(istream &input, student &s)                    //input data for class student
{
	cout << "enter student name:";
	input >> s.name;
	cout << "enter rollno:";
	input >> s.roll_no;
	cout << endl << "enter marks1,marks2 and marks3:" << endl;
	input >> s.marks1 >> s.marks2 >> s.marks3;
	return input;
}
ostream& operator<<(ostream &output, student s)                  //display data of student class
{
	output << "student roll no:" << s.roll_no;
	output << " " << "student name:" << s.name << endl;
	output << "Marks:" << s.marks1 << " " << s.marks2 << " " << s.marks3 << endl;
	output << "Grade:" << s.grade << endl;
	return output;
}
void generate_results(student *s, int n)                         //to calculate total and grade of each student
{
	int i;
	for (i = 0; i < n; i++)
	{
		s[i].total = s[i].marks1 + s[i].marks2 + s[i].marks3;
		if (s[i].total > 180)
			s[i].grade = 'a';
		else if (100 < s[i].total &&s[i].total < 190)
			s[i].grade = 'b';
		else if (80 < s[i].total &&s[i].total < 110)
			s[i].grade = 'c';
		else if (0 <= s[i].total &&s[i].total < 81)
			s[i].grade = 'd';
		else
			cout << "Enter valid marks" << endl;                       //if negative marks are entered
	}
}
void main()
{
	int i, n;
	cout << "Enter the no of students to be displayed:";
	cin >> n;
	student *s;                                                        //pointer to student array
	s = new student[n];                                                  //dynamic allocation of memory for n objects of class
	for (i = 0; i < n; i++)
	{
		cin >> s[i];                                                   //input data of all objects
	}
	generate_results(s, n);                                            //generate grade for each student
	for (i = 0; i < n; i++)
	{
		cout << s[i];                                                  //output details of each student
	}
	system("pause");
}