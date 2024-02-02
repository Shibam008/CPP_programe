
/*
given array -> [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]

our ans will be ->[0, 1, 2, 3, 4, 2, 2, 3, 3, 4]

we have to return K value . where K stands for total number of unique element.

in this example K = 5 as we have [0, 1, 2, 3, 4, .......]
*/
#include<bits/stdc++.h>
using namespace std;

int removeDuplicate(vector<int> &nums){
    
    int i=1, j=0;
    while(i < nums.size()){
        if(nums[i] == nums[j]) i++;
        else(nums[++j] = nums[i++]);   // pre increment of j and post increment of i
    
        // else{
        //     j++;
        //     nums[j] = nums[i];
        //     i++;
        // }
        
    }
    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    return j + 1 ; // this is the value of K.
}

int main(){
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int ans = removeDuplicate(nums);
    cout<<"\nNumber of unique elements are : "<<ans<<endl;
}