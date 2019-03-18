/*matrix-vector multiplication*/
#include<iostream>
using namespace std;
class vector;
class matrix {
	int a[10][10];
public:
	void get_matrix(int x, int y)
	{
		int i, j;
		for (i = 0; i < x; i++)
			for (j = 0; j < y; j++)
				cin >> a[i][j];
	}
	void dis_matrix(int x, int y)
	{
		int i, j;
		cout << "The matrix elements are:" << endl;
		for (i = 0; i < x; i++)
			for (j = 0; j < y; j++)
				cout << a[i][j];
	}
	friend void mul_matrix(matrix &m1, vector &v1);
};
class vector {
	int v[10];
public:
	void get_vector(int x)
	{
		int i;
		for (i = 0; i < x; i++)
			cin >> v[i];
	}
	void dis_vector(int x)
	{
		int i;
		cout << "The elements are:" << endl;
		for (i = 0; i < x; i++)
			cout << " " << v[i];
	}
	friend void mul_matrix(matrix &m1, vector &v1);
};
void mul_matrix(matrix &m1, vector &v1);
void main()

{
	int y;
	matrix m1;
	vector v1;
	m1.get_matrix(2, 2);
	m1.dis_matrix(2, 2);
	v1.get_vector(2);
	v1.dis_vector(2);
	mul_matrix(m1, v1);
	cin >> y;
}
void mul_matrix(matrix &m1, vector &v1)
{
	int c[2] = { 0 }, i, j;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
			c[i] += m1.a[i][j] * v1.v[j];
	}
	cout << endl << "The result is " << endl;
	for (i = 0; i < 2; i++)
		cout << " " << c[i];
}