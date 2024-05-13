#include<iostream>
using namespace std;
void checkLastOccur(string str, char target, int index, int&ans){
    // base case
    if(index >= str.length()) {
        return;
    }
    // handle one case
    if(str[index] == target) {
        ans = index;
    }
    // recursive call
    checkLastOccur(str, target, index+1, ans);
}

int main() {
    string str = "abbcddefgdh";
    char target;
    cout<<"enter char : ";
    cin>>target;

    int ans = -1;
    checkLastOccur(str, target, 0, ans);
    cout<<ans<<endl;
    
}