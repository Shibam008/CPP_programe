#include<iostream>
using namespace std;

void print_array(int *arr, int size, int index){

    if(index >= size){
        return;
    }
    cout << arr[index] << " ";

    print_array(arr, size, index+1);
}

int main(){
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr)/sizeof(int);
    print_array(arr, size, 0);
   
}