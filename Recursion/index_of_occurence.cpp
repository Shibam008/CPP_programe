#include<iostream>
#include<vector>
using namespace std;
int findOcc(int *arr, int size, int target, vector<int>&ans, int index){

    if(index >= size){
        return -1;
    }

    if(arr[index] == target){
        ans.push_back(index);
    }

    findOcc(arr, size, target, ans, index+1);
}
int main(){
    int arr[]={10, 20, 45, 10, 65, 85, 10, 23, 10};
    int size = sizeof(arr)/sizeof(int);
    int target = 10;
    vector<int> ans;
    findOcc(arr, size, target, ans, 0);

    for(int val: ans){
        cout << val <<" ";
    }
    

}