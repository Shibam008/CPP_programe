#include<bits/stdc++.h>
using namespace std;

void subset(vector<int> arr, int idx, vector<int> output, vector<vector<int>>& ans) {
   // base case 
   if(idx >= 3) {
      ans.push_back(output);
      return;
   }
   // exclude
   subset(arr, idx+1, output, ans);
   // include
   int currElem = arr[idx];
   output.push_back(currElem);
   subset(arr, idx+1, output, ans);
}

int main() {
   vector<int> nums = {1,2,3};
   vector<vector<int> > ans;
   vector<int> output;
   subset(nums, 0, output, ans);

   for(int i=0; i<ans.size(); i++) {
      cout<< "{ ";
      for(int j=0; j<ans[i].size(); j++) {
         cout << ans[i][j] << " ";
      }
      cout << "}" << endl;
   }
   return 0;
}