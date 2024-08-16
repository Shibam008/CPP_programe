#include<iostream>
using namespace std;

//! MaxHeap Creation -> O(nlogn) time complexity
//! MaxHeap Delete -> O(logn) time complexity

class MaxHeap {
public:

    int * arr;
    int size;
    int capacity;

    MaxHeap(int n) {
        arr = new int[n];
        size = 0;
        capacity = n;
    }

    void insert(int value)  // Step up
    {
        if(size == capacity) {
            cout << "Heap overflow!" << endl;
            return;
        }

        arr[size] = value;
        int idx = size;
        size++;

        // compare it with its parent
        while(idx > 0 && arr[(idx-1)/2] < arr[idx]) {
            swap(arr[idx], arr[(idx-1)/2]);
            idx = (idx-1)/2;
        }

        cout << arr[idx] << " is inserted into the heap" << endl;
    }

    void Heapify(int idx) 
    {
        int largest = idx;
        int left = 2*idx + 1; // left child index
        int right = 2*idx + 2; // right child index


        // largest variable stores large value index between (parent, left, right) node.
        if(left < size && arr[left] > arr[largest]) {
            largest = left;
        }
        if(right < size && arr[right] > arr[largest]) {
            largest = right;
        }

        if(largest != idx) {
           swap(arr[idx], arr[largest]);
           Heapify(largest); 
        }
    }

    void deleteNode()  // step down
    {  
        //* Always delete top node , and replace it only with last node for maintaing the CBT property.

        if(size == 0) {
            cout << "Heap underflow!";
            return;
        }

        cout << arr[0] << " is deleted from heap" << endl;
        arr[0] = arr[size-1];  // Replace 1st node by last node
        size--;

        if(size == 0) return;

        Heapify(0);

    }

    void print() {
        cout << "Heap implementation : ";
        for(int i=0; i<size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main () {
    MaxHeap hp(10);
    hp.insert(2);
    hp.insert(12);
    hp.insert(21);
    hp.insert(14);
    hp.insert(6);
    hp.insert(8);
    hp.insert(5);

    hp.print();

    hp.deleteNode();

    hp.print();


}