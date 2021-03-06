#include <string>
#include <iostream>
#include <stack>

using namespace std;

/**
 * A structure holding customer details
 */
struct Customer {

    char customerName[15];
    int arrivalTime;
    int serviceTime;
    int finishTime;

};


struct FCFSQueue {

    Customer customerList[100];
    int length;
};


class Queue {

    FCFSQueue fcfsQueue;   // queue

public:

    Queue() {
        this->fcfsQueue.length = 0;        // assign initial length to 0. ie; queue is empty.
    }

    bool isEmpty() {
        return this->fcfsQueue.length == 0;
    }

    int getLength(){
        return this->fcfsQueue.length;
    }

    /**
     * Insert a customer object into queue.
     * @param customer
     */
    void Enqueue(Customer customer){

        if(this->fcfsQueue.length >= 100){
            cout<<"Queue is full. Can not add customer. \n exiting...";
            return;
        }
        this->fcfsQueue.customerList[fcfsQueue.length] = customer;  // insert customer at position - length
        ++this->fcfsQueue.length;  // increment queue length
        cout<<"\n"<<customer.customerName << " added to the queue";
    }

    /**
     * Remove element from front of the queue.
     */
    void Dequeue(){

        // if queue is empty, there is nothing to remove.
        if(isEmpty()){
            cout<<"No customers in the queue.";
            return;
        }

        Customer customer = this->fcfsQueue.customerList[0];  // get customer object at position zero. ie; front of the queue

        cout<<"\n"<<customer.customerName << " is removed from the queue";

        // overwrite array elements with element in next position. This will replace element at pos 0 with element at pos 1.
        for (int i = 0; i < getLength(); ++i) {
            this->fcfsQueue.customerList[i] = this->fcfsQueue.customerList[i+1];
        }
        --this->fcfsQueue.length;  // Decrement length of the queue.
    }

};

int main() {

    Queue Q;   // create an empty queue

    // Create three customer objects
    Customer customer[3];

    for (int i = 0; i < 3; ++i) {
        cout << "Enter customer name: ";
        cin.get(customer[i].customerName, 50);
        cout << "Enter arrival time :  ";
        cin >> customer[i].arrivalTime;
        cout << "Enter service time :  ";
        cin >> customer[i].serviceTime;
        cout << "Enter Finish time :  ";
        cin >> customer[i].finishTime;
        getchar();
    }

    cout<<"\n Initial queue Length : " <<Q.getLength();
    // Enqueue three customers

    Q.Enqueue(customer[0]);
    Q.Enqueue(customer[1]);
    Q.Enqueue(customer[2]);

    cout<<"\n Queue length after insertion : "<<Q.getLength();

    // Dequeue an element

    Q.Dequeue();

    cout<<"\n Queue length after removal : "<<Q.getLength();

    return 0;
}
