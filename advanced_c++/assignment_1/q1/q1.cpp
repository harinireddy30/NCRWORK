#include<iostream>
using namespace std;
struct node {
	int data;
	struct node *prev;
	struct node *next;
};
class Dequeue {
	struct node *front;
	struct node *rear;
public:
	Dequeue()
	{
		front = rear = NULL;
	}
	void insert_front(int element)
	{
		struct node *temp;
		temp = new node;
		temp->data = element;
		if (front == NULL && rear == NULL)
		{
			front = rear = temp;
			temp->prev = NULL;
			temp->next = NULL;
		}
		else
		{
			temp->next = front;
			temp->prev = NULL;
			front->prev = temp;
			front = front->prev;
		}
	}
	void insert_rear(int element)
	{
		struct node *temp;
		temp = new node;
		temp->data = element;
		if (front == NULL && rear == NULL)
		{
			front = rear = temp;
			temp->prev = temp->next = NULL;
		}
		else
		{
			rear->next = temp;
			temp->prev = rear;
			temp->next = NULL;
			rear = rear->next;
		}
	}
	int delete_front()
	{
		struct node *temp;
		temp = front;
		int ele_deleted;
		ele_deleted = front->data;
		front = front->next;
		front->prev = NULL;
		delete temp;
	}
	int delete_rear()
	{
		struct node *temp;
		temp = rear;
		int ele_deleted;
		ele_deleted = rear->data;
		rear = rear->prev;
		rear->next = NULL;
		delete temp;
	}
	void display()
	{
		struct node *temp;
		temp = front;
		while (temp != rear)
		{
			cout << temp->data << "--";
			temp = temp->next;
		}
		cout << temp -> data << endl;
	}
};
class Stack :private Dequeue {
public:
	void push(int element)
	{
		insert_front(element);
	}
	int pop()
	{
		int ele_deleted;
		ele_deleted=delete_front();
	}
};
class queue :private Dequeue {
public:
	void push(int element)
	{
		insert_rear(element);
	}
	int pop()
	{
		int ele_deleted;
		ele_deleted = delete_front();
	}
};
int main()
{
	Dequeue d1;
	d1.insert_front(2);
	d1.insert_front(3);
	d1.insert_rear(4);
	d1.display();
	system("pause");
	return 0;
}