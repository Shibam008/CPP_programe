#include<iostream>
#include<vector>
using namespace std;

// ** Important   ||  Binary Search

int find_first_occurence(vector<int> &arr, int n, int target){
    int start = 0;
    int end = n-1; 
    int ans = -1;

    while(start <= end){

        int mid = start + (end - start)/2;

        if(arr[mid] == target){
            ans = mid; //store ans
            end = mid-1;          //move to left (as first occurenece always stay left side, we perform our algorithm on the left part of array)
        }
        else if(target > arr[mid]){
            start = mid+1; //move to right
        }
        else if(target < arr[mid]){
            end = mid-1; //move to left
        }
    }
    return ans;
}


int find_last_occurence(vector<int> &arr, int n, int target){
    int start = 0;
    int end = n-1; 
    int ans = -1;

    while(start <= end){

        int mid = start + (end - start)/2;

        if(arr[mid] == target){
            ans = mid; //store ans
            start = mid+1;        //move to right (as last occurenece always stay right side, we perform our algorithm on the right part of array)
        }
        else if(target > arr[mid]){
            start = mid+1; //move to right
        }
        else if(target < arr[mid]){
            end = mid-1; //move to left
        }
    }
    return ans;
}


int find_total_occurence(vector<int> &arr, int n, int target){
    
    int firstocc = find_first_occurence(arr,n,target);
    int lastocc = find_last_occurence(arr,n,target);
    int totalocc = lastocc - firstocc + 1;
    return totalocc;
}


int main(){
    vector<int> arr = {1,2,3,5,5,5,5,8};
    int size = arr.size();
    int target;
    cout<<"Enter target value : ";
    cin>>target;

    int ans1 = find_first_occurence(arr,size,target);
    cout<<"First occurence at index : "<<ans1<<endl;

    int ans2 = find_last_occurence(arr,size,target);
    cout<<"Last occurence at index : "<<ans2<<endl;

    int ans3 = find_total_occurence(arr,size,target);
    cout<<"total occurence : "<<ans3<<endl;

}