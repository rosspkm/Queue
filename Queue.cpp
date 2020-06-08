#include <iostream>
#include <string>
using namespace std;

struct CUSTOMER
{
	string CustomerName;
	int ArrivalTime, ServiceTime, FinishTime;
};

struct FCFSQUEUE
{
	CUSTOMER CustomerList[100];
	int length;
};

bool IsEmpty(FCFSQUEUE queue)
{
	if (queue.length == 0) {
		return true;
	}
	else
		return false;
}

int GetLength(FCFSQUEUE queue)
{
	return queue.length;
}

void Enqueue(FCFSQUEUE& queue, CUSTOMER cus)
{
	if (queue.length >= 100)
	{
		cout << "The Queue is full." << endl;
	}
	queue.CustomerList[queue.length] = cus;
	++queue.length;
	cout << "Customer " << cus.CustomerName << " has been added to the queue." << endl;
	cout << endl;
}

void DeQueue(FCFSQUEUE& queue, CUSTOMER cus)
{
	if (IsEmpty(queue))
	{
		cout << "The queue is empty." << endl;
	}
	cus = queue.CustomerList[0];
	cout << "Customer " << cus.CustomerName << " has left the queue." << endl;
	for (int i = 0; i < queue.length; ++i) {
		queue.CustomerList[i] = queue.CustomerList[i + 1];
	}
	--queue.length;
}

int main()
{
	FCFSQUEUE myQueue;
	CUSTOMER newCus;
	myQueue.length = 0;
	for (int i = 0; i < 3; i++)
	{
		cout << "What is the customers name: ";
		cin >> newCus.CustomerName;
		cout << endl;
		cout << "What is the arrival time: ";
		cin >> newCus.ArrivalTime;
		cout << endl;
		cout << "What is the service time: ";
		cin >> newCus.ServiceTime;
		cout << endl;
		cout << "What is the finish time: ";
		cin >> newCus.FinishTime;
		cout << endl;
		Enqueue(myQueue, newCus);
	}

	DeQueue(myQueue, newCus);
	cout << "Customer :" << newCus.CustomerName << "is leaving the queue" << endl;
	DeQueue(myQueue, newCus);
	cout << "Customer :" << newCus.CustomerName << "is leaving the queue" << endl;
	DeQueue(myQueue, newCus);
	cout << "Customer :" << newCus.CustomerName << "is leaving the queue" << endl;

	return 0;
}