#include<iostream>
using namespace std;


void print(struct node *);

struct node
{
	int data;
	struct node * next;
};

class LL
{
	struct node * start;

public:

	LL();

	void insert_beg(int);
	void insert_end(int);
	void insert_after(int, int);
	void insert_before(int, int);

	int delete_beg();
	int delete_end();
	void delete_spec(int);

	void travel_forward();
	void travel_backward();

	void reverse();

	~LL();

	friend void print(struct node*);
};

LL::LL()
{
	start = NULL;
}

void LL::insert_beg(int ele)
{
	struct node *temp;
	temp = new node;

	temp->data = ele;
	temp->next = start;
	start = temp;
}

void LL::insert_end(int ele)
{
	struct node *temp;
	temp = new node;

	temp->data = ele;
	temp->next = NULL;

	if (start == NULL)
		start = temp;
	else
	{
		struct node *curr;
		curr = start;

		while (curr->next != NULL)
			curr = curr->next;
		curr->next = temp;
	}
}

void LL::insert_after(int ele, int sele)
{
	if (start != NULL)
	{
		struct node *curr;
		curr = start;

		while (curr != NULL && curr->data != sele)
			curr = curr->next;

		if (curr != NULL)
		{
			struct node * temp;
			temp = new node;

			temp->data = ele;
			temp->next = curr->next;
			curr->next = temp;
		}
		else
			cout << "Element not found" << endl;
	}
	else
		cout << "Linked List is empty" << endl;
}

void LL::insert_before(int ele, int sele)
{
	if (start != NULL)
	{
		struct node *temp;
		if (start->data == NULL)
		{
			temp = new node;
			temp->data = ele;
			temp->next = start->next;
			start = temp;
		}
		else
		{
			struct node *curr;
			curr = start;

			while (curr->next != NULL && curr->next->data != sele)
				curr = curr->next;

			if (curr->next != NULL)
			{
				temp = new node;
				temp->data = ele;
				temp->next = curr->next;
				curr->next = temp;
			}
			else
				cout << "Element not found" << endl;
		}
	}
	else
		cout << "Linked List is empty" << endl;
}

int LL::delete_beg()
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
		cout << "Linked List is empty" << endl;

	return x;
}

int LL::delete_end()
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
			struct node *curr;
			curr = start;

			while (curr->next->next != NULL)
				curr = curr->next;
			x = curr->next->data;
			delete curr->next;
			curr->next = NULL;
		}
	}
	else
		cout << "Linked List is empty" << endl;

	return x;
}

void LL::delete_spec(int ele)
{
	if (start != NULL)
	{
		struct node *temp;
		if (start->data == ele)
		{
			temp = start;
			start = start->next;
			delete temp;
		}

		else
		{
			struct node *curr;
			curr = start;

			while (curr->next != NULL && curr->next->data != ele)
				curr = curr->next;

			if (curr->next != NULL)
			{
				temp = curr->next;
				curr->next = temp->next;
				delete temp;
			}
			else
				cout << "Element not found" << endl;
		}
	}
	else
		cout << "Linked List is empty" << endl;

}

void LL::travel_forward()
{
	if (start != NULL)
	{
		struct node *curr;
		curr = start;
		while (curr != NULL)
		{
			cout << curr->data << "-->";
			curr = curr->next;
		}
	}
	cout << "NULL" << endl;
}

void LL::travel_backward()
{
	cout << "NULL";
	if (start != NULL)
		print(start);
	cout << endl;
}

void print(struct node *curr)
{
	if (curr != NULL)
	{
		print(curr->next);
		cout << "<--" << curr->data;
	}
}

void LL::reverse()
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

LL::~LL()
{
	struct node *temp;
	while (start != NULL)
	{
		temp = start;
		start = temp->next;
		delete temp;
	}
}

int main()
{
	int ch, num, p, res;
	LL L;

	cout << "Operation" << endl << endl;
	cout << "1.Insertion at beginning" << endl;
	cout << "2.Insertion at end" << endl;
	cout << "3.Insertion after element" << endl;
	cout << "4.Insertion before element" << endl;
	cout << "5.Deletion from beginning" << endl;
	cout << "6.Deletion from end" << endl;
	cout << "7.Deletion of an element" << endl;
	cout << "8.Traverse Forward" << endl;
	cout << "9.Traverse Backward" << endl;
	cout << "10.Reverse" << endl;
	cout << "11.Exit" << endl;

	while (1)
	{
		cout << "Select option:" << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:cout << "Enter element to insert: ";
			cin >> num;
			L.insert_beg(num);
			break;
		case 2: cout << "Enter element to insert: ";
			cin >> num;
			L.insert_end(num);
			break;
		case 3: cout << "Enter element to insert: ";
			cin >> num;
			cout << "Enter element after which to insert:";
			cin >> p;
			L.insert_after(num, p);
			break;
		case 4: cout << "Enter element to insert: ";
			cin >> num;
			cout << "Enter element before which to insert:";
			cin >> p;
			L.insert_before(num, p);
			break;
		case 5:res = L.delete_beg();
			cout << "Deleted from the beginning = " << res << endl;
			break;
		case 6:res = L.delete_end();
			cout << "Deleted from the end= " << res << endl;
			break;
		case 7: cout << "Enter element to delete: ";
			cin >> num;
			L.delete_spec(num);
			break;
		case 8:L.travel_forward();
			break;
		case 9:L.travel_backward();
			break;
		case 10:L.reverse();
			//cout<<"Reversed Linked List:"<<endl;
			break;
		case 11:exit(0);
		default:cout << "Wrong Option" << endl;
		};
	}
	return 0;

}