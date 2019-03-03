#include<iostream>
using namespace std;
void bubble_sort(int arr[], int n)
{
	int i, j, temp;
	for(i=0;i<(n-1);i++)
		for (j = 0; j < (n - 1 - i); j++)
		{
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
}
int main()
{
	cout << "Enter the number of elements u want to enter" << endl;
	int size, i;
	cin >> size;
    int *p;
	p = new int[size];
	cout << "Enter the elements in the array" << endl;
	for (i = 0; i < size; i++)
		cin >> p[i];
	cout << "The elements before sorting are:"<<endl;
	for (i = 0; i < size; i++)
		cout << p[i] << " ";
	bubble_sort(p, size);
	cout << endl<<"The elements after sorting are:" << endl;
	for (i = 0; i < size; i++)
		cout << p[i] << " ";
	system("pause");
}