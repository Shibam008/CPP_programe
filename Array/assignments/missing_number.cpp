#include<iostream>
#include<vector>
using namespace std;

//missing element/number er ei Question tar best solution  [Binary Search]  use kore korte hoy.

// **checkout this problem on "searching & sorting" folder

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
    vector<int> nums = {9,0,2,1,3,6,5,4,7};
    int ans = missingnum(nums);
    cout<<"Missing number is : "<<ans<<endl;
}
//time complexity - O(n).