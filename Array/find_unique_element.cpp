#include<iostream>
using namespace std ;

int getunique(int arr[], int size){
    int ans = 0;
    for(int i=0; i<size; i++){
        ans = ans^arr[i];
    }
    return ans;
}

int main(){
    int arr[]={10,10,2,3,5,3,5,6,9,2,9};
    int size = 11;
    int finalans = getunique(arr,size);
    cout<< "Unique element in this array is : "<<finalans;
}