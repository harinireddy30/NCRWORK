#include<iostream>
using namespace std;
class queue
{
	int *array;
	int size;
	int rear;
	int front;
public:
	queue()
	{
		rear = front = -1;
		array = NULL;
		size = 0;
	}
	void set_size(int n)
	{
		size = n;
		array = new int[n];
	}
	void enqueue(int ele)
	{
		if (overflow())
		{
			cout << "The queue is FULL"<<endl;
		}
		else
		{
			if (underflow())
			{
				rear = 0;
				front = 0;
				array[rear] = ele;
			}
			else
			{
				rear = (rear + 1) % size;
				array[rear] = ele;
			}
		}
	}

	int dequeue()
	{
		int x = -99;
		if (underflow())
		{
			cout << "The queue is EMPTY" << endl;
		}
		else
		{
			if (rear == front)
			{
				x = array[rear];
				rear = front = -1;
			}
			else
			{
				x = array[front];
				front = (front + 1) % size;
			}
		}
		return x;
	}
	bool underflow()
	{
		return (front == -1 && rear == front);
	}
	bool overflow()
	{
		return (front == (rear + 1) % size);
	}
	void display()
	{
		int i;
		if (underflow())
			cout << "Empty Queue" << endl;
		else 
	    {
			for (i = front; i != rear; i = (i + 1) % size)
			{
				cout << array[i] << "--";
			}
			cout << array[i]<< endl;
		}
	}
	~queue()
	{
		delete array;
	}
};

int main()
{
	queue q1;
	cout << "Enter the size of the queue : ";
	int size;
	cin >> size;
	q1.set_size(size);
	while (1)
	{
		cout << "Enter the operation to be performed on circular queue:" << endl;
		cout << "1.Enqueue  2.Dequeue  3.Check overflow  4.Check underflow  5.Display the elements 6.EXIT" << endl;
		int x;
		cin >> x;
		switch (x)
		{
		case 1:int ele;
			   cout << " __ENQUEUE operation__:Enter the element to add: ";
			   cin >> ele;
			   q1.enqueue(ele);
			   break;
		case 2:	int x;
			    x = q1.dequeue();
			    cout << "__DEQUEUE operation__:The element deleted is:" << x;
			    break;
		case 3: if (q1.overflow())
			    cout << "OVERFLOW" << endl;
				else
			    cout << "NO OVERFLOW" << endl;
			    break;
		case 4:	if (q1.underflow())
			    cout << "UNDERFLOW" << endl;
				else
			    cout << "NO UNDERFLOW"<<endl;
			    break;
		case 5:q1.display();
			   break;
		case 6:exit(0);
		
		default:cout << "Enter a valid option"<<endl;
			    break;
		}
	}
	system("pause");
return 0;
}