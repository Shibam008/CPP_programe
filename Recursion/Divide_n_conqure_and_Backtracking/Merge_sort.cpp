#include<iostream>
using namespace std;

void merge(int *arr, int s, int e){

    int mid = s + (e-s)/2;

    int left_len = mid-s+1;
    int right_len = e - mid;

    // creat dynamic array in Heap memory using "new" keyword 
    int *left = new int[left_len];
    int *right = new int[right_len];


    //copying values from original to new arrays
    // copying in left array
    int k = s;
    for(int i=0; i<left_len; i++){
        left[i] = arr[k];
        k++;
    }
    // copying in right array
    k = mid+1;
    for(int i=0; i<right_len; i++){
        right[i] = arr[k];
        k++;
    }


    // Actual merge (left and right arrays are sorted)
    int left_index = 0;
    int right_index = 0;
    int mainArrayIndex = s;  // most important line

    while(left_index < left_len && right_index < right_len){

        if(left[left_index] < right[right_index]){
            arr[mainArrayIndex] = left[left_index];
            mainArrayIndex++;
            left_index++;
        }
        else{
            arr[mainArrayIndex] = right[right_index];
            mainArrayIndex++;
            right_index++;
        }
    }


    // handle extra 2 cases
    // Case - 1 : left array exhaust but there are some element in right array
    while(right_index < right_len){
        arr[mainArrayIndex] = right[right_index];
        mainArrayIndex++;
        right_index++;
    }
    // Case - 2 : right array exhaust but there are some element in left array
    while(left_index < left_len){
        arr[mainArrayIndex] = left[left_index];
        mainArrayIndex++;
        left_index++;
    }

    delete[] left;
    delete[] right;
}

void mergeSort(int *arr, int s, int e){
    // base case 
    if(s >= e ){
        return;
    }
    // breaking array 
    int mid = s + (e-s)/2;
    //recursive call for left array
    mergeSort(arr, s, mid);
    //recursive call for right array
    mergeSort(arr, mid+1, e);
    //actual merge
    merge(arr, s, e);
}

int main(){
    int arr[] = {15, 45, 21, 31, 14, 62, 32, 55};
    int size = sizeof(arr)/sizeof(int);
    int s = 0;
    int e = size-1;

    mergeSort(arr, s, e);

    cout<<"After sorting : ";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}