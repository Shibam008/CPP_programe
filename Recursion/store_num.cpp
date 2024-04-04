// store the even numbers in vector using recursion

#include<iostream>
#include<vector>
using namespace std;
void findEven(int *arr, int size, vector<int>&ans, int index){

    if(index >= size){
        return;
    }

    if(arr[index] % 2 == 0){
        ans.push_back(arr[index]);
    }

    findEven(arr, size, ans, index+1);
}
int main(){
    int arr[]={1, 2, 4, 5, 9, 7, 6};
    int size = sizeof(arr)/sizeof(int);
    vector<int> ans;

    findEven(arr, size, ans, 0);

    for(int num: ans){
        cout<< num <<" ";
    }
}