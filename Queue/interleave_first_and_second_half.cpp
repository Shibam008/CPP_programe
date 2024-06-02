/*
    given input - 10|20|30|40|50|60|70|80
   expected out - 10|50|20|60|30|70|40|80
*/

#include<bits/stdc++.h>
using namespace std;

void interleaveQueue(queue<int>&first) {
    queue<int>second;

    int n = first.size();
    int mid = n/2;
    // push first-half of first-queue in second queue
    for(int i=0; i<mid; i++) {
        int elem = first.front();
        first.pop();
        second.push(elem); 
    }
    // merge both halves into original queue
    for(int i=0; i<mid; i++) {
        int temp = second.front();
        second.pop();
        first.push(temp);

        temp = first.front();
        first.pop();
        first.push(temp);
    }

    // // handling odd case
    // if(mid%2 == 0 || mid%2 == 1) {
    //     int temp = first.front();
    //     first.pop();
    //     first.push(temp);
    // }
}

int main() {
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    interleaveQueue(q);

    cout<<"Queue : ";
    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }
}