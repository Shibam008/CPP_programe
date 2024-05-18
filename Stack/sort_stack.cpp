#include <bits/stdc++.h>
using namespace std;

void insertAtSortedStack(stack<int> &st, int element) {
    // base case
    if(st.empty() || element > st.top()) {  // ** st.empty()  is most important condition
        st.push(element);
        return;
    }
    // handle
    int temp = st.top();
    st.pop();
    // re
    insertAtSortedStack(st, element);
    //bt
    st.push(temp);
}

void sortStack(stack<int> &st) {
    if(st.empty()) {
        return;
    }
    
    int temp = st.top();
    st.pop();

    sortStack(st);

    insertAtSortedStack(st, temp);
}


int main() {
    stack<int> st;
    st.push(10);
    st.push(40);
    st.push(30);
    st.push(50);
    st.push(20);

    sortStack(st);

    cout<<"Stack : ";
    while(!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;

    
   return 0;
}