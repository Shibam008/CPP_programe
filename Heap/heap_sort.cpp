/*

 Build maxHeap
 sort array -> 1. swap last elem and 1st elem
               2. Heapify  
*/

#include<iostream>
using namespace std;

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
    for(int i = (n/2)-1; i >= 0; i--) {
        Heapify(arr, i, n);
    }
}

void sortArray(int arr[], int n) 
{
    for(int i = n-1; i >= 0; i--) {
        swap(arr[i], arr[0]);
        Heapify(arr, 0, i);  
        // with the help of heapify we are sending arr[0] element to its right position
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
    int arr[] = {10, 30, 40, 90, 50, 20, 60, 80, 70};
    int size = sizeof(arr)/sizeof(int);
    buildMaxHeap(arr, size);
    sortArray(arr, size);
    printHeap(arr, size);
}