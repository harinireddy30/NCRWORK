#include<iostream>
using namespace std;
class queue
{
	int *p;                       //pointer pointing to queue
	int size;                     //size of the array
	int rear; 
	int front;
public:

	queue()
	{
		rear = -1;
		front = -1;
		p= NULL;
	}
	void set_data(int n)
	{
		size = n;
		p = new int[n];
	}

	bool overflow()
	{
		return (rear == size - 1);
	}

	bool underflow()
	{
		return (front != rear);
	}
	void enqueue(int ele)
	{
		if (!overflow())
			p[++rear] = ele;
		else
			cout << "queue is full" << endl;
	}
	int dequeue()
	{
		int x = -999;
		if (!underflow())
			x = p[++front];
		else
			cout << "Empty queue" << endl;
		return x;
	}
	void display()
	{
		for (int i = front + 1;i <= rear;i++)
			cout << p[i] << "  ";
	}

	~queue()
	{
		delete p;
	}
};

void main()
{
	queue q1;
	int x;
	int n;
	cout << "Enter size of queue: ";
	cin >> n;
	q1.set_data(n);                           //set size and pointer to array
	while(1)
	{
		cout <<"Enter ur choice" << endl;
		cout << "1.enqueue  2.dequeue  3.display" << endl;
		cin >> x;
		switch (x)
		{
		    case 1: 
		    {	int ele;
		    	cout << "Enter the element to enqueue: ";
		    	cin >> ele;
			    q1.enqueue(ele);
				break;
		    }
		   case 2: 
		   {	int d;
		        d = q1.dequeue();
		        cout << endl << "dequeued element:" << d << endl;
		        break;
		   }
		   case 3: 
		   {
			q1.display();
			break;
		   }
		   default:cout << "Enter a valid option" << endl;
		}

	}
}