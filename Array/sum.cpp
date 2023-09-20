#include<iostream>
using namespace std ;
int main (){
    int arr[5];
    int size = 5;
    cout<<"Enter numbers : ";
    for(int i=0; i<size; i++){
        cin>>arr[i];
        cout<< "In index "<<i<<" stored : "<<arr[i]<<endl;
    }
    int sum=0;
    for(int i=0; i<size; i++){
        sum=sum+arr[i];
    }
    cout<<"Sum of array : "<<sum;
}