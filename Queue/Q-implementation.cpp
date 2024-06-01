#include<iostream>
using namespace std;

class Queue {
    public:
        int *arr;
        int size;
        int front;
        int rear;

        Queue(int size) {
            arr = new int[size];
            this->size = size;
            front = -1;
            rear = -1;
        }

        void push(int val) {
            if(rear == size-1) {
                cout<<"Queue is full"<<endl;
                return;
            }
            else if(front == -1 && rear == -1) {
                // empty queue
                front++; 
                rear++;
                arr[rear] = val;
            }
            else {
                rear++;
                arr[rear] = val;
            }
        }

        void pop() {
            if(front == -1 && rear == -1) {
                cout<<"Empty Queue"<<endl;
                return;
            }
            else if(front == rear) {
                // single element;
                arr[front] = -1;
                front = -1;
                rear = -1;
            }
            else {
                arr[front] = -1;
                front++;
            }
        }

        bool isEmpty(){
            if(front == -1 && rear == -1) {
                return true;
            }
            else return false; 
        }

        int getSize() {
            if(front == -1 && rear == -1) { // empty case
                return 0;
            }
            else {
                return (rear - front + 1);
            }
        }

        int getFront() {
            if(front == -1) {
                cout<<"No element present in queue";
                return -1;
            }
            else return arr[front];
        }

        int getRear() {
            if(rear == -1) {
                cout<<"Queue is empty";
                return -1;
            }
            else return arr[rear];
        }

        void print() {
            cout<<endl<<"Front : "<<front<<" | "<<"Rear : "<<rear<<endl;
            cout<<"Queue : ";
            for(int i=0; i<size; i++) {
                cout<<arr[i]<<" ";
            }cout<<endl;
        }
};

int main() {
    Queue q(5);
    q.print();

    q.push(10);
    q.print();

    q.push(80);
    q.print();

    q.push(60);
    q.print();

    q.push(30);
    q.print();

    q.push(50);
    q.print();

    q.pop();
    q.print();

    q.push(500);
 


    cout<<"Size of queue : "<<q.getSize();
    
}