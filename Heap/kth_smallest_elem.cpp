#include<bits/stdc++.h>
using namespace std;

int findKthSmallest(int * arr, int n, int k) 
{
    priority_queue<int> pq;  //! Max heap

    // process k elements first
    for(int i=0; i<k; i++) {
        int elem = arr[i];
        pq.push(elem);
    }

    //compare remaining element and insert into heap if any elem is smaller than root of heap
    for(int i=k; i<n; i++) {
        int elem = arr[i];
        if(elem < pq.top()) {
            pq.pop();
            pq.push(elem);
        }
    }

    int ans = pq.top();
    return ans;
}

int findKthLargest(int * arr, int n, int k) 
{
    priority_queue<int, vector<int>, greater<int> > pq;  //! Min heap

    // process k elements first
    for(int i=0; i<k; i++) {
        int elem = arr[i];
        pq.push(elem);
    }

    //compare remaining element and insert into heap if any elem is greater than root of heap
    for(int i=k; i<n; i++) {
        int elem = arr[i];
        if(elem > pq.top()) {
            pq.pop();
            pq.push(elem);
        }
    }

    int ans = pq.top();
    return ans;
}

int main() {
    int arr[] = {1, 9, 6, 3, 4, 8};
    int size = 6;
    int k = 3;

    //int ans = findKthSmallest(arr, size, k);
    int ans = findKthLargest(arr, size, k);
    cout << " k-th largest elements : " << ans << endl;
}