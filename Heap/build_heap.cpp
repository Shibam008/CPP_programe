#include<iostream>
using namespace std;

//! For building maxHeap using STEP DOWN approch it takes " O(n) " time 

void Heapify(int arr[], int idx, int n) 
{
    int largest = idx;
    int left = 2*idx + 1;
    int right = 2*idx + 2;

    if(left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if(largest != idx) {
        swap(arr[idx], arr[largest]);
        Heapify(arr, largest, n);
    }
}

void buildMaxHeap(int arr[], int n) 
{
    // step down //! O(n)
    // step down process always start from (n/2)-1

    for(int i = (n/2)-1; i >= 0; i--) {    
        Heapify(arr, i, n);
    }
}

void printHeap(int arr[], int n) 
{
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 12, 3, 5, 4, 32, 62, 19};
    int size = sizeof(arr)/sizeof(int);
    buildMaxHeap(arr, size);
    printHeap(arr, size);
}