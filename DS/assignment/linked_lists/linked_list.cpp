#include<iostream>
using namespace std;
void print(struct node *p);
struct node {
	int data;
	struct node *next;
};
class list
{
	struct node *start;
public:
	list();
	void insert_beg(int);
	void insert_end(int);
	void insert_after(int, int);
	void insert_before(int, int);
	int delete_beg();
	int delete_end();
	void delete_spec(int);
	void travel_forward();
	void travel_backward();
	void reversal();
	~list();
	friend void display(struct node*);
};
list::list()
{
	start = NULL;
}
void list::insert_beg(int ele)
{
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->next = start;
	start = temp;
}
void list::insert_end(int ele)
{
	struct node *temp;
	temp = new node;
	temp->data = ele;
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
void list::insert_after(int ele, int after)
{
	if (start == NULL)
		cout << "Empty list" << endl;
	else
	{
		struct node *p;
		p = start;
		while (p != NULL && p->data != after)
			p = p->next;
		if (p == NULL)
			cout << "Element not found" << endl;
		else
		{
			struct node *temp;
			temp = new node;
			temp = new node;
			temp->data = ele;
			temp->next = p->next;
			p->next = temp;
			
		}
	}
}
void list::insert_before(int ele, int before)
{
	if (start == NULL)
		cout << "Empty linked list" << endl;
	else
	{
		if (start->data == before)
		{
			struct node *temp;
			temp = new node;
			temp->data = ele;
			temp->next = start;
			start = temp;
		}
		else
		{
			struct node *p;
			p = start;
			while (p->next != NULL && p->next->data != before)
				p = p->next;
			if (p->next != NULL)
			{
				struct node *temp;
				temp = new node;
				temp->data = ele;
				temp->next = p->next;
				p->next = temp;
			}
			else
				cout << "Element not found" << endl;
		}
	}
}
int list::delete_beg()
{
	int x = -9999;
	if (start != NULL)
	{
		struct node *temp;
		temp = start;
		x = temp->data;
		start = start->next;
		delete temp;
	}
	else
		cout << "Empty linked list" << endl;
	return x;
}
int list::delete_end()
{
	int x = -9999;
	if (start != NULL)
	{
		if (start->next == NULL)
		{
			x = start->data;
			delete start;
			start = NULL;
		}
		else
		{
			struct node *p;
			p = start;
			while (p->next->next != NULL)
				p = p->next;
			x = p->next->data;
			delete p->next;
			p->next = NULL;
		}
	}
	else
		cout << "Empty list" << endl;
	return x;
}
void list::delete_spec(int ele)
{
	if (start == NULL)
		cout << "Empty list" << endl;
	else
	{
		struct node *temp;
		if(start->data==ele)
		{
			temp = start;
			start = start->next;
			delete temp;
		}
		else
		{
			struct node *p;
			p = start;
			while (p->next != NULL && p->next->data != ele)
				p = p->next;
			if (p->next != NULL)
			{
				temp = p->next;
				p->next = temp->next;
				delete temp;
			}
			else
				cout << "Element not found" << endl;
		}
	}
}
void list::travel_forward()
{
	if (start == NULL)
		cout << "Empty list" << endl;
	else
	{
		struct node *p;
		p = start;
		while (p != NULL)
		{
			cout << p->data << "-->";
			p = p->next;
		}
	}
}
void list::travel_backward()
{
	cout << "NULL";
	if (start != NULL)
		print(start);
	cout << endl;
}
void print(struct node *p)
{
	if (p != NULL)
	{
		print(p->next);
		cout << "<--" << p->data;
	}
}
void list::reversal()
{
	struct node *temp, *rev;
	rev = NULL;
	if (start != NULL && start->next != NULL)
	{
		while (start != NULL)
		{
			temp = start;
			start = temp->next;
			temp->next = rev;
			rev = temp;
		}
		start = rev;
	}
}
list::~list()
{
	struct node *temp;
	while (start != NULL)
	{
		temp = start;
		start = temp->next;
		delete temp;
	}
}
void main()
{
	int x, i;
	list l;
	cout << "Enter your choice:" << endl;
	cout << "1.Insert beginning 2.Insert end 3.Insert after 4.Insert before" << endl;
	cout<<"5.Delete beginning 6.Delete End 7.Delete specific element 8.Travel forward" << endl;
	cout << "9.Travel backward 10.Reverse 11.Print" << endl;
	cout << endl;
	while (1)
	{
		cout << "Enter ur choice" << endl;
		cin >> i;
		switch (i)
		{
		case 1:
		{
			int a;
			cout << "Enter element to insert at beginning:";
			cin >> a;
			l.insert_beg(a);
			break;
		}
		case 2:
		{
			int a;
			cout << "Enter element to insert at end:";
			cin >> a;
			l.insert_end(a);
			break;
		}
		case 3:
		{
			int a, ele;
			cout << "Insert element to be inserted and after which element:";
			cin >> ele;
			cin >> a;
			l.insert_after(ele, a);
			break;
		}
		case 4:
		{
			int a, ele;
			cout << "Insert element to be inserted and before which element:";
			cin >> ele;
			cin >> a;
			l.insert_before(ele, a);
			break;
		}
		case 5:
		{
			int a;
			cout << "The deleted element is:";
			a = l.delete_beg();
			cout << a;
			break;
		}
		case 6:
		{
			int a;
			cout << "The deleted element is:";
			a = l.delete_end();
			cout << a;
			break;
		}
		case 7:
		{
			int a;
			cout << "Enter element to be deleted:";
			cin >> a;
			l.delete_spec(a);
			break;
		}
		case 8:
		{
			l.travel_forward();
			break;
		}
		case 9:
		{
			l.travel_backward();
			break;
		}
		case 10:
		{
			l.reversal();
			break;
		}
		default:cout << "Wrong option" << endl;
		}
	}
}