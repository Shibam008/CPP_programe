#include<iostream>
#include<limits.h>

using namespace std ;

int findminimum(int arr[], int size){
    int minAns = INT_MAX;
    for(int i=0; i<size; i++){
        if(arr[i]<minAns){
            minAns=arr[i];
        }
    }
    return minAns;
}

int main (){
    int arr[]={5,20,60,8,40,1,-6,9,3};
    int size = 9;

    int minimum = findminimum(arr,size);
    cout << "Minimum value in the array is : "<<minimum<<endl;
}