/*define linkedlist class and include the following member functions:
 1)insert at nth position in the list
 2)reverse the list
 3)printf elements in forward direction
 4)print elements in reverse direction
 5)delete a node with particular value.*/

#include<iostream>
using namespace std;
struct node {
	int data;
	struct node *next;                   //struct node with data and pointer to next node
};
class ll {
	struct node *start;
public:
	ll()
	{
		start = NULL;                   //default value of pointer
	}
	void insert_n_pos(int n,int ele)   
	{
		struct node *temp;             //creation of temp node and assigning data and next pointer to it
		temp = new node[50];
		temp->data = ele;             
		temp->next = NULL;              
		if (start == NULL)
			start = temp;
		else
		{
			struct node *curr;
			curr = start;
			int i = 0;
			while (i < n-1)               //traverse till (n-1)th position
				curr = curr->next;
			temp->next = curr->next;            //insertion of node
			curr->next = temp;
		}
	}
	void print_backward()
	{
		cout << "NULL";
		if (start != NULL)
			print(start);
		cout << endl;
	}
	void print(struct node *p)
	{
		if (p!= NULL)
		{
			print(p->next);
			cout << "<--" << p->data;
		}
	} 
	void del_spec(int ele)
	{
		struct node *curr, *temp;
		curr = start;
		while (curr->next->data != ele)             //traverse until the data field of next node is the element specified
		{
			curr = curr->next;
		}
		temp = curr->next;                          //temp points to the node to be deleted
		curr->next = temp->next;
		delete temp;
	}
	void rev()
	{
		struct node *temp, *rev;
		rev = NULL;
		if (start == NULL)
			cout << "Empty list" << endl;
		else if (start->next = NULL)
			cout << "Only one element in the list.Unable to reverse." << endl;
		else
		{
			while (start != NULL)
			{
				temp = start;
				start = temp->next;
				temp->next = rev;              //makes next node point to the previous node
				rev = temp;
			}
			start = rev;
		}
	}
	void print_forward()
	{
		struct node *temp;
		temp = start;
		while (temp != NULL)
		{
			cout << temp->data << "-->";
			temp = temp->next;
		}
	}
};
int main()
{
	ll list_1;
	int x, n, ele;
	while (1)
	{
		cout << endl<<"Enter the option: 1)Insert at nth position 2)print forward 3)print backward 4)reverse 5)Exit" << endl;
		cin >> x;
		switch (x)
		{
		  case 1: 
		  {
			cout << "enter the position to enter and the element to insert:" << endl;
			cin >> n >> ele;
			list_1.insert_n_pos(n,ele);
			break;
		  }
		  case 2:
		  {
			  cout << "The elements in forward direction are:" << endl;
			  list_1.print_forward();
			  break;
		  }
		  case 3:
		  {
			  cout << "Printing elements in backward order:" << endl;
			  list_1.print_backward();
			  break;
		  }
		  case 4:
		  {
			  cout << "reversing the elements:" << endl;
			  list_1.rev();
			  break;
		  }
		  case 5:exit(0);
			  break;
		}
	}
	system("pause");
	return 0;
}
