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

    for(int i=0; i<result.size(); i++){  
        cout<<result[i];
    }
    
    return 0;
}

// chat gpt helps me to write the correct loop condition that is    [i < result.size()]    but I was writing   [i < num]   which is wrong

//Here, num is the input number, and you are using it as the loop condition to iterate over the result vector. The problem is that result may have more digits than the original num. For example, if num is 5, and the factorial result is 120, then result will have three digits (1, 2, 0), but your loop is only going up to num, which is 5. This causes an out-of-bounds access when you try to access result[3] and result[4].