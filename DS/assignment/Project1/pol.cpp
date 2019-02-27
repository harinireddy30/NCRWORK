#include<iostream>
using namespace std;
struct node {
	int coef, exp;
	struct node *next;
};
class poly {
	struct node *start;
public:
	poly()
	{
		start = NULL;
	}
	void add_ele(int c, int e)
	{
		struct node *temp;
		temp = new node;
		temp->coef = c;
		temp->exp = e;
		temp->next = NULL;
		if (start == NULL)
			start = temp;
		else
		{
			struct node *p;
			p = start;
			while (p->next != NULL)
				p = p->next;
			p->next = temp;
		}
	}
	poly add_poly(poly p1, poly p2)
	{
		struct node *x1,*x2;
		x1 = p1.start;
		x2 = p2.start;
		while (x1 != NULL && x2 != NULL)
		{
			if()
		}
	}
};