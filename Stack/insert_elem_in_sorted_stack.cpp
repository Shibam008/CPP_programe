#include <bits/stdc++.h>
using namespace std;
void insertAtSortedStack(stack<int> &st, int element) {
    // base case
    if(st.empty() || element > st.top()) {  // **** handle empty case is the most imp part
        st.push(element);
        return;
    }
    // handle one case
    int temp = st.top();
    st.pop();
    // recursive call
    insertAtSortedStack(st, element);
    //back track
    st.push(temp);
}
int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    int elem;
    cout<<"Enter element : ";
    cin>>elem; 

    insertAtSortedStack(st, elem);

    cout<<"Stack : ";
    while(!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;

    
   return 0;
}