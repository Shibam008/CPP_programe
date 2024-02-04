/*
Problem statement -> "Apply Binary search on nearly sorted array"  important interview question.

nearly sorted means --> one element which is at i-th index in sorted array it could be at [       (i-1) or i or (i+1)   ]-th index in nearly sorted array.

example->

nearly sorted = [20, 10, 30, 50, 40, 70, 60]
sorted array  = [10, 20, 30, 40, 50, 60, 70]
*/

#include<bits/stdc++.h>
using namespace std ;
int searchNearlySorted(vector<int> &arr, int x){
    
    int s = 0;
    int e = arr.size()-1;
    int size = arr.size();
    int ans = -1;

    while(s <= e){
        int mid = s + (e-s)/2;

        if(mid-1 >= 0 && arr[mid-1] == x) return mid-1;
        if(arr[mid] == x) return mid;
        if(mid+1 < size && arr[mid+1] == x) return mid+1;

        if(arr[mid] < x){
          s = mid + 2; // here we can use [s = mid+1;] but we don't want to compare same element twice.ans will be same if we use [s = mid+1;]
        }
        else{
            e = mid - 2;
        }
    }
    return ans;
}
int main(){
    vector<int> arr = {20, 10, 30, 50, 40, 70, 60};
    int target;
    cout<<"Enter tagret value : ";
    cin>>target;
    int targetIndex = searchNearlySorted(arr, target);

    if(targetIndex == -1){
        cout << "Target not found"<<endl;
    }
    else{
        cout<<"Target found at index : "<<targetIndex<<endl;
    }

}
