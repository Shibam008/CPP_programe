#include<iostream>
using namespace std;

bool checkSorted(int *arr, int size, int index){

    if( index >= size){
        return true;
    }

    if(arr[index] > arr[index-1]){
        //ckeck again
        bool nextAns = checkSorted(arr, size, index+1);
        return nextAns;
    }
    else{
        return false;
    }

    
}
int main(){
    int arr[]={10, 20, 30, 40, 50, 70};
    int size = sizeof(arr)/sizeof(int);
    bool ans = checkSorted(arr, size, 1);
    
    if(ans){
        cout<< "Array is sorted" << endl;
    }
    else{
        cout<< "Array is not sorted" << endl;
    }
}