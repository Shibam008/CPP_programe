#include<bits/stdc++.h>
using namespace std;

void printFirstNegative(int *arr, int n, int k) {

    deque<int>dq;
    // process first k elements i.e first window
    for(int i=0; i<k; i++) {
        int element = arr[i];
        if(element < 0) {
            dq.push_back(i);
        }
    }

    // process remaining windows -> removal & addition
    for(int index=k; index<n; index++) {
        // ans of previous window
        if(dq.empty()) {
            cout<<"0 "<<endl;
        }else {
            cout<<arr[dq.front()]<<" ";
        }

        // removal - remove index that is out of range
        if(index - dq.front() >= k) {
            dq.pop_front();
        }
        // addition
        if(arr[index] < 0) {
            dq.push_back(index);
        }
    }

    // ans of last window
    if(dq.empty()) {
        cout<<"0 "<<endl;
    }else {
        cout<<arr[dq.front()]<<" ";
    }

}
int main() {
    int arr[] = {2, -5, 4, -1, -2, 0, 5};
    int size = 7;
    int k = 3;
    printFirstNegative(arr, size, k);

}