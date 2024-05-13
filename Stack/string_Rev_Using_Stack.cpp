#include<bits/stdc++.h>
using namespace std;
int main() {
    string str = "rock";
    stack<char> st;

    for(auto ch : str) {
        st.push(ch);
    }

    while( !st.empty() ) {
        cout<<st.top();
        st.pop();
    }
    cout<<endl;
}