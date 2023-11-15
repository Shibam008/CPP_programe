#include<iostream>
#include<vector>
using namespace std;
int missingnum(vector<int> &nums){
    int ans=0;
//XOR of all values/elements of array.
    for(int i=0; i<nums.size(); i++){
        ans = ans^nums[i];
    }
//XOR of all index of array
    for(int i=0; i<=nums.size(); i++){
        ans = ans^i;
    }
    return ans;
}
int main(){
    vector<int> nums;
    nums.push_back(9);
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(6);
    nums.push_back(5);
    nums.push_back(4);
    nums.push_back(7);

    int ans = missingnum(nums);
    cout<<"Missing number is : "<<ans<<endl;
}