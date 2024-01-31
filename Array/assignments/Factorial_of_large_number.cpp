#include <bits/stdc++.h>
using namespace std;
// resource - Coder army (youtube lecture 40)
vector<int> large_fact(int num){
     
    vector<int> ans(1,1);

    while(num > 1){

        int carry = 0, res, size = ans.size();

        for(int i=0; i<size; i++){
            res = ans[i] * num + carry;
            ans[i] = res % 10;
            carry = res / 10;
        }
        while(carry){
            ans.push_back(carry%10);
            carry /= 10;
        }
        num--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    int num;
    cout<<"Enter a positive integer number : ";
    cin>>num;
    vector<int> result = large_fact(num);

    for(int i=0; i<result.size(); i++){  // chat gpt helps me to write the correct loop condition that is    [i < result.size()]    but I was writing   [i < num]   which is wrong
        cout<<result[i];
    }
    return 0;
}