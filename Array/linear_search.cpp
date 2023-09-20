//given array [2,5,8,6,10,9]
//target value = 8
#include<iostream>
using namespace std ;

bool linearsearch(int arr[], int size, int target){
    for(int i=0; i<size; i++){
        if(arr[i]==target){
            return true;
        }
    }
    return false;
}

int main (){
    int arr[]={2,5,8,6,10,9};
    int size =5;
    int target ;
    cout<<"enter your target value : ";
    cin>>target;

    bool ans = linearsearch(arr,size,target);
    if(ans==true){
        cout<<"target value found";
    }
    else{
        cout<<"target value not found";
    }
}