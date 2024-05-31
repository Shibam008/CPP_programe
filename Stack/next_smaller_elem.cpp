#include<bits/stdc++.h>
using namespace std;
// P.S : travarse array and if the next element is smaller than current then update that current element else -1.
vector<int> nextSmallerElem(int *arr, int size, vector<int>&ans) {

    stack<int>st;
    st.push(-1);

    for(int i = size-1; i >= 0; i--) {
        int curr = arr[i];
        while(st.top() >= curr) {
            st.pop();
        }
        // storing ans 
        ans[i] = st.top(); 
        // keeping track of elements and updating
        st.push(curr);
    }
    return ans;
}

int main() {
    int arr[] = {4, 1, 6, 3};
    int size = sizeof(arr) / sizeof(int);

    vector<int>ans(size); 
    ans = nextSmallerElem(arr, size, ans);
    for(auto val : ans) {
        cout<<val<<" ";
    }cout<<endl;
    
    return 0;
}
