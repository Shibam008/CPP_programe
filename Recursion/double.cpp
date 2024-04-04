// given [10, 20, 30]
// output [20, 40, 60]

#include<iostream>
#include<vector>
using namespace std;
void valDouble(int *arr, int size, int index, vector<int>&ans){

    if(index >= size){
        return;
    }

    ans.push_back(arr[index]*2);

    valDouble(arr, size, index+1, ans);
}
int main(){
    int arr[]={1, 2, 4, 5, 9, 7, 6};
    int size = sizeof(arr)/sizeof(int);
    vector<int> ans;
    valDouble(arr, size, 0, ans);

    for(int val: ans){
        cout<<val<<" ";
    }
}