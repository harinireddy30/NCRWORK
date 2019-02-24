#include<iostream>
using namespace std;
struct node
{
	int coeff, exp;
	struct node *next;
};
class poly
{
	struct node *start;
public:
	poly()
	{
		start = NULL;
	}
	void add_ele(int ele, int exp)
	{
		struct node *temp;
		temp = new node;
		temp->coeff = ele;
		temp->exp = exp;
		temp->next = NULL;
		if (start != NULL)
		{
			struct node *p;
			p= start;
			while (p->next != NULL)
				p = p->next;
			p->next = temp;
		}
		else
			start = temp;
	}
	poly add_poly(poly p1, poly p2)
	{
		struct node *t1, *t2;
		t1 = p1.start;
		t2 = p2.start;
		while (t1 != NULL && t2 != NULL)
		{
			struct node *temp;
			temp = new node;
			temp->next = NULL;
			if (t1->exp == t2->exp)
			{
				temp->coeff = t1->coeff + t2->coeff;
				temp->exp = t1->exp;
				cout << temp->coeff << " " << temp->exp<< endl;
				if (start == NULL)
					start = temp;
				else
				{
					struct node *t = start;
					while (t->next != NULL)
						t = t->next;
					t->next = temp;
				}
				t1 = t1->next;
				t2 = t2->next;
			}
			else if (t1->exp > t2->exp)
			{
				temp->coeff = t1->coeff;
				temp->exp = t1->exp;
				cout << temp->coeff << " " << temp->exp << endl;
				if (start == NULL)
					start = temp;
				else
				{
					struct node *p = start;
					while (p->next != NULL)
						p = p->next;
					p->next = temp;
				}
				t1 = t1->next;
			}
			else
			{
				temp->coeff = t2->coeff;
				temp->exp = t2->exp;
				cout << temp->coeff << " " << temp->exp << endl;
				if (start == NULL)
					start = temp;
				else
				{
					struct node *p = start;
					while (p->next != NULL)
						p = p->next;
					p->next = temp;
				}
				t1 = t1->next;
			}
		}
		while (t1 != NULL)
		{
			struct node *temp;
			temp = new node;
			temp->coeff = t1->coeff;
			temp->exp = t1->exp;
			temp->next = NULL;
			struct node *t = start;
			while (t->next != NULL)
				t = t->next;
			t->next = temp;
			t2 = t2->next;
		}
		while (t2 != NULL)
		{
			struct node *temp;
			temp = new node;
			temp->next = NULL;
			temp->coeff = t2->coeff;
			temp->exp = t2->exp;
			struct node *t = start;
			while (t->next != NULL)
				t = t->next;
			t->next = temp;
			t2 = t2->next;
		}


		return (*this);
	}
	void display()
	{
		struct node *t = start;
		while (t != NULL)
		{
			cout << t->coeff << "x^" << t->exp;
			if (t->next != NULL)
				cout << "+";
			t = t->next;
		}
		cout << endl;
	}

};
int main()
{
	poly p1, p2, p3;
	cout << "Enter 1st ploynomial:\n";
	int c, e;
	char ch;
	do
	{
		cout << "Coeff & power:";
		cin >> c >> e;
		p1.add_ele(c, e);
		cout << "continue(y/n)?";
		cin >> ch;
	} while (ch == 'y');
	cout << "Enter 2nd ploynomial:\n";
	do
	{
		cout << "Coeff & power:";
		cin >> c >> e;
		p2.add_ele(c, e);
		cout << "continue(y/n)?";
		cin >> ch;
	} while (ch == 'y');
	p1.display();
	p2.display();
	p3.add_poly(p1, p2);
	p3.display();
	system("pause");
	return 0;
}