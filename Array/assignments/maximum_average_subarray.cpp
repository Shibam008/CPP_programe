#include<bits/stdc++.h>
using namespace std;

double slidingWindow_approach(vector<int> &nums, int k){
      int i = 0, j = k-1;
      int sum = 0;

      for(int s=i; s<=j; s++){  // don't do mistake again . [ <= ] not only [ < ]
        sum += nums[s];
      }

      int maxSum = sum;
      j++;  // here we checking j if there exist a next element or out-of-bound.
      while(j < nums.size()){  //sliding window 
        sum -= nums[i++];
        sum += nums[j++];
        maxSum = max( maxSum , sum );
      }

      double maxAvg = maxSum / (double) k;
      return maxAvg;
}

int main(){
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4; //subarray size
    double ans = slidingWindow_approach(nums, k);
    cout<<"Average of maximum sub-array of given array is = "<<ans<<endl;


}