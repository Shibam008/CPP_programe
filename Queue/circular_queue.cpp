#include<iostream>
using namespace std;

class Cqueue {
    public:
        int *arr;
        int size;
        int front;
        int rear;

        Cqueue(int size) {
            arr = new int[size];
            this->size = size;
            front = -1;
            rear = -1;
        }

        void push(int val) {
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

        void pop() {
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

        void print() {
            cout<<endl<<"Front : "<<front<<" | "<<"Rear : "<<rear<<endl;
            cout<<"Circular queue : ";
            for(int i=0; i<size; i++) {
                cout<<arr[i]<<" ";
            }cout<<endl;
        }
};

int main() {
    Cqueue cq(5);
    cq.print();

    cq.push(13);
    cq.push(19);
    cq.push(18);
    cq.push(23);
    cq.push(93);
    cq.print();

    cq.push(12);

    cq.pop();
    cq.pop();
    cq.print();

    cq.push(100);
    cq.print();

    cq.push(200);
    cq.print();

    cq.push(300);

    cq.pop();
    cq.print();
}