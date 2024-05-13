#include<iostream>
using namespace std;
void reverseString(string &str, int s, int e) {
    // base case
    if(s >= e) {
        return;
    }
    // handle one case
    swap(str[s], str[e]);
    // recursive call
    reverseString(str, s+1, e-1);
}
int main() {
    string str = "madam";
    int s = 0;
    int e = str.size()-1;
    
    reverseString(str, s, e);
    for(auto ch : str){
        cout<<ch;
    }
}