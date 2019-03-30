#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector <int> vector1;
	int i;
	vector1.push_back(1);
	vector1.push_back(2);
	for (i = 0; i < vector1.size(); i++)
		cout << vector1[i];
}