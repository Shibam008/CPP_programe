#include<iostream>
using namespace std;

bool checkPalindrome(string str, int s, int e) {
    // base case
    if(s >= e) return true;

    // handle one case
    if(str[s] != str[e]) return false;

    // recursive call
    return checkPalindrome(str, s+1, e-1);
}
int main() {
    string str = "shibam";
    int s = 0;
    int e = str.size()-1;
    bool ans = checkPalindrome(str, s, e);
    if(ans) {
        cout<<"palindrome"<<endl;
    }
    else cout<<"not a palindrome !"<<endl;
}