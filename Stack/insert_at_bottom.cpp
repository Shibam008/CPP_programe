#include <bits/stdc++.h>
using namespace std;

void solution_1(stack<int>&st, int&size, int element) {
    // Base case
    if(size == 0) {
        st.push(element);
        return ;
    }
    // solve one case
    size--;
    int temp  = st.top();
    st.pop();
    
    // recursive call
    solution_1(st, size, element);

    // Backtracking 
    st.push(temp);
}

void solution_2(stack<int> &st, int element) {
    // Base case
    if(st.empty()) {
        st.push(element);
        return;
    }

    int temp = st.top();
    st.pop();

    solution_2(st, element);

    st.push(temp);
}
int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    
    int element;
    cout<<"Enter element : ";
    cin>>element;

    int len = st.size();
    //solution_1(st, len, element);
    solution_2(st, element);

    cout<<"Added element to the bottom : ";
    while(!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }
   return 0;
}