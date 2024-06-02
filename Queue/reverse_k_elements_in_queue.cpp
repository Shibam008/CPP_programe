/*
    1. Push first k emen from queue to stack

    2. Push all K elem from stack to queue

    3. Now we have (n-k) elem in the queue at wrong position(means at start). So pop that (n-k) elements and push back
*/

#include<bits/stdc++.h>
using namespace std;

void reverseKelem(queue<int>&q, int k) {
    stack<int> st;
    int n = q.size();
    int leftElem = n-k;

    if(k > n || k == 0) {
        return;
    }
    // step 1
    while(k--) {
        int q_elem = q.front();
        q.pop();
        st.push(q_elem);
    }
    // step 2
    while(!st.empty()) {
        int st_elem = st.top();
        st.pop();
        q.push(st_elem);
    }
    // step 3
    while(leftElem--) {
        int elem = q.front();
        q.pop();
        q.push(elem);
    }
}


int main() {
    queue<int> q;
    int k = 3;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    reverseKelem(q,k);

    cout<<"Queue : ";
    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }
}