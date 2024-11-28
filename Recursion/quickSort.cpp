#include<iostream>
using namespace std;

int partition(int arr[], int s, int e) {
    
    int pivot = arr[s];

    // counting total numbers, smaller than pivot
    int cnt = 0;
    for(int i = s+1; i<=e; i++) {
        if(arr[i] <= pivot) cnt++;
    }

    // placing pivot at right position
    int pivotIdx = s + cnt;
    swap(arr[pivotIdx], arr[s]);

    // set small values to the left of the pivot
    // set large values to the right of the pivot

    int i = s, j = e;

    while(i < pivotIdx && j > pivotIdx) 
    {
        while(arr[i] <= pivot) i++;
        while(arr[j] > pivot) j++;

        if(i < pivotIdx && j > pivotIdx) {
            swap(arr[i], arr[j]);
        }
    }

    return pivotIdx;
}

void quicksort(int arr[], int s, int e) {
    // base case
    if(s >= e) return;

    int p = partition(arr, s, e);

    quicksort(arr, s, p-1);
    quicksort(arr, p+1, e);
}

int main () {
    int arr[] = {10, 50, 30, 20, 40, 60};
    int n = 6;

    quicksort(arr, 0, n-1);

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }cout << endl;

    return 0;
}