#include<iostream>
using namespace std;

int binSearch(int *arr, int s, int e, int target){

    if(s > e){
        return -1;
    }

    int mid = s + (e-s)/2;
    if(arr[mid] == target){
        return mid;
    }

    if(arr[mid] < target){
        // move to right
        return binSearch(arr, mid+1, e, target);
    }
    else{
        //move left
        return binSearch(arr, s, mid-1, target);
    }
}
int main(){
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int size = sizeof(arr)/sizeof(int);

    int start = 0;
    int end = size-1;

    int target;
    cout<<"Enter target : ";
    cin>>target;

    int findIndex = binSearch(arr, start, end, target);
    
    if(findIndex != -1){
        cout << "Target found at index : " << findIndex <<endl;
    }
    else{
        cout << "Target not found !"<<endl;
    }
}