#include<iostream>
using namespace std;
void checkLastOccur_L2R(string str, char target, int index, int&ans){
    // base case
    if(index >= str.length()) {
        return;
    }
    // handle one case
    if(str[index] == target) {
        ans = index;
    }
    // recursive call
    checkLastOccur_L2R(str, target, index+1, ans);
}

void checkLastOccur_R2L(string str, char target, int index, int&ans){
    // base case
    if(index <= 0) {
        return;
    }
    // handle one case
    if(str[index] == target) {
        ans = index;
        return;
    }
    // recursive call
    checkLastOccur_R2L(str, target, index-1, ans);
}

int main() {
    string str = "abbcddefgdh";
    int size = str.length();

    char target;
    cout<<"enter char : ";
    cin>>target;

    int ans = -1;
    checkLastOccur_L2R(str, target, 0, ans);
    //checkLastOccur_R2L(str, target, size-1, ans);
    cout<<ans<<endl;
    
}