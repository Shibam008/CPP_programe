#include<iostream>
#include<vector>
using namespace std;

int prefixSumApproch(vector<int> &nums){
    vector<int>lsum(nums.size(), 0);
    vector<int>rsum(nums.size(), 0);

    for(int i=1; i<nums.size(); i++){
        lsum[i] = lsum[i-1] + nums[i-1];
        cout<<lsum[i]<<" ";
    }
cout<<endl;
    for(int i=nums.size()-2; i>=0; i--){
        rsum[i] = rsum[i+1] + nums[i+1];
        cout<<rsum[i]<<" ";
    }
cout<<endl;
    for(int i=0; i<nums.size(); i++){
        if(lsum[i] == rsum[i])
        cout<<"Pivot index is = "<<i<<endl;
    
    }
}

int main(){
    vector<int>nums;
    nums.push_back(1);
    nums.push_back(7);
    nums.push_back(3);
    nums.push_back(6);
    nums.push_back(5);
    nums.push_back(6);

prefixSumApproch(nums);

    // for(int i=0; i<nums.size(); i++){
    //     cout<<nums[i]<<" ";
    // }

return 0;
}
