#include<bits/stdc++.h>
using namespace std;

void reverseQueue(queue<int>&q) {
    stack<int> st;
    // take elements from queue and insert it in a stack
    while(!q.empty()) {
        int frontElem = q.front();
        q.pop();
        st.push(frontElem);
    }
    // take elemnts from stack and insert it in a queue and done.
    while(!st.empty()) {
        int revElem = st.top();
        st.pop();
        q.push(revElem);
    }
}

void recursiveSoln(queue<int>&q) {
    // base case
    if(q.empty()) return;

    int element = q.front();
    q.pop();
    recursiveSoln(q);
    q.push(element);
}
int main() {
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    //reverseQueue(q);
    recursiveSoln(q);

    cout<<"Reversed queue : ";
    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }

}