#include<iostream>
#include<vector>
using namespace std;
int sortcolors(vector<int> &nums){ //in-place method.
    int left=0, mid=0, right = nums.size()-1;

    while(mid<=right){
        if(nums[mid]==0){
            swap(nums[left],nums[mid]);
            left++, mid++;
        }
        else if(nums[mid]==1){
            mid++;
        }
        else{//nums[mid]==2
            swap(nums[right],nums[mid]);
            right--;
        }
    }
}

int main(){
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(0);
    nums.push_back(1);

    sortcolors(nums);
    
    cout<<"Sorted colors -> ";
    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}