#include<iostream>
#include<vector>
using namespace std;

int pivotIndex(vector<int> &nums){
    int s = 0;
    int e = nums.size()-1;

    while(s <= e){
        int mid = s + (e-s)/2;
        //corner case (if we given an single element)
        if(s == e){
            return s;
        }

        if(mid+1 < nums.size() && nums[mid] > nums[mid+1])
         return mid;

        else if(mid-1 >= 0 && nums[mid] < nums[mid-1])
         return mid-1;

        else if(nums[s] > nums[mid])
         e = mid-1;

        else s = mid+1;
    }
    return -1;
}

int binarySearch(vector<int> &nums, int s, int e, int target){
    
    while(s <= e){
        int mid = s + (e - s)/2;

        if(nums[mid] == target){
            return mid; 
        }
        else if(target > nums[mid]){
            s = mid+1; 
        }
        else if(target < nums[mid]){
            e = mid-1; 
        }       
    }
    return -1;
}

int search(vector<int> &nums, int target){
     int pivot_index = pivotIndex(nums);
     int n = nums.size();
     int ans = -1;

     if(target >= nums[0] && target <= nums[pivot_index]){
        ans = binarySearch(nums, 0, pivot_index, target);
     }

     else{
        ans = binarySearch(nums, pivot_index + 1, n-1, target);
     }
     return ans;

}

int main(){
    vector<int> nums = {12, 14, 16, 2, 4, 8, 9, 10};
    int key;
    cout<<"Enter target value : ";
    cin>>key;

    int ans = search(nums, key);
    
    if(ans == -1){
        cout<<"Target does not exsist in the given array"<<endl;
    }
    else cout<<"Target found at index -> "<<ans<<endl;
}