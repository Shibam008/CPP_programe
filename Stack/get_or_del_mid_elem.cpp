#include <bits/stdc++.h>
using namespace std;

void solutionDeleteElem(stack<int>&st, int&pos, int&ans) {
    // Base case
    if(pos == 1) {
        cout<<"Deleting "<<st.top()<<endl;
        st.pop();
        return ;
    }
    // solve one case
    pos--;
    int temp  = st.top();
    st.pop();
    
    // recursive call
    solutionDeleteElem(st, pos, ans);

    // Backtracking 
    st.push(temp);
}

void solutionGetElem(stack<int>&st, int&pos, int&ans) {
    // Base case
    if(pos == 1) {
        ans = st.top();
        return ;
    }
    // solve one case
    pos--;
    int temp  = st.top();
    st.pop();
    
    // recursive call
    solutionGetElem(st, pos, ans);
    //solutionDeleteElem(st, pos, ans);


    // Backtracking 
    st.push(temp);
}


int getMiddleElement(stack<int> &st) {
    int size = st.size();
    if(size == 0) {
        cout<<"Stack is empty"<<endl;
        return -1;
    }
        
    else {
        int pos = 0;
        if(size & 1) {   // odd case
            pos = (size/2) + 1;
        }
        else{
            pos = size/2;  // even case
        } 
        int ans = -1;
        solutionGetElem(st, pos, ans);
        //solutionDeleteElem(st, pos, ans);

        return ans;
    }
}


int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    //cout<<"Befor size : "<<st.size()<<endl;

    int mid = getMiddleElement(st);
    cout<<"Middle element = "<<mid<<endl;

    //cout<<"After deleting size : "<<st.size()<<endl;
    return 0;

    
}