#include<iostream>
using namespace std;

class Deque {
    public:
        int *arr;
        int size;
        int front;
        int rear;

        Deque(int size) {
            arr = new int[size];
            this->size = size;
            front = -1;
            rear = -1;
        }

        void pushFront(int val) {
            // 1. Overflow
            if(front == 0 && rear == size-1 || front-rear == 1) {
                cout<<"Overflow"<<endl;
            }
            // single element
            else if(front == -1 && rear == -1) {
                front++;
                rear++;
                arr[front] = val;
            }
            // circular nature
            else if(front == 0 && rear != size-1) {
                front = size-1;
                arr[front] = val;
            }
            // normal flow
            else{
                front--;
                arr[front] = val;
            }
        }

        void pushBack(int val) {
            // 1. Overflow
            if(front == 0 && rear == size-1 || front-rear == 1) {
                cout<<"Overflow"<<endl;
            }
            // 2. Empty case -> first element
            else if(front == -1 && rear == -1) {
                front++;
                rear++;
                arr[rear] = val;
            }
            // 3. Circular nature
            else if(rear == size-1 && front != 0) {
                rear = 0;
                arr[rear] = val;
            }
            // 4. normal flow
            else {
                rear++;
                arr[rear] = val;
            }
        }

        void popFront() {
            // 1. Underflow
            if(front == -1 && rear == -1) {
                cout<<"Underflow"<<endl;
            }
            // 2. Single element
            else if(front == rear) {
                arr[front] = -1;
                front = -1;
                rear = -1;
            }
            // 3. Circular nature
            else if(front == size-1) {
                arr[front] = -1; 
                front = 0;
            }
            // 4. normal flow
            else {
                arr[front] = -1;
                front++;
            }
        }

        void popBack() {
            // 1. Underflow
            if(front == -1 && rear == -1) {
                cout<<"Underflow"<<endl;
            }
            // 2. Single element
            else if(front == rear) {
                arr[front] = -1;
                front = -1;
                rear = -1;
            }
            // 3. circular case
            else if(rear == 0) {
                arr[rear] = -1;
                rear = size-1;
            }
            else {
                arr[rear] = -1;
                rear--;
            }
        }
};

int main() {
    
}