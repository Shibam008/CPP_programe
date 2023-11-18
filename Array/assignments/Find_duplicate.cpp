#include<iostream>
#include<vector>
using namespace std;
int findDuplicate(vector<int> &nums){
    
    while(nums[0] != nums[nums[0]]){
        swap(nums[0], nums[nums[0]]);
    }
    //else
    return nums[0];
}
int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(2);

int ans = findDuplicate(nums);
cout<<"The duplicate element is = "<<ans;

    return 0;
}