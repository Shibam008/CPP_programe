#include <bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int> &st, int element){
    if(st.empty()) {
        st.push(element);
        return;
    }
    // handle one case
    int temp = st.top();
    st.pop();
    // recursive call
    insertAtBottom(st, element);
    // backtracking
    st.push(temp);
}

void reverseStack(stack<int> &st) {
    if(st.empty()) {
        return;
    }
    // handle one case
    int temp = st.top();
    st.pop();
    // recursive call
    reverseStack(st);
    // Backtracking
    insertAtBottom(st, temp);
}
int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    // cout<<"Stack : ";
    // while(!st.empty()) {
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }cout<<endl;

    reverseStack(st);

    cout<<"Reversed Stack : ";
    while(!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;

    
   return 0;
}