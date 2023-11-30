#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter number of rows : ";
    cin>>n;

    for(int i=1; i<=(2*n)-1; i++){
        cout<<i<<" ";
    }
    cout<<endl;


// int a=1;

    for(int row=0; row < n-1; row++){
        int a=1;
        for(int col=0; col<n-row-1; col++){
            cout<<a<<" ";
            a++;
        }
        for(int col=0; col<(2*row)+1; col++){
            cout<<"  ";
            a++;
        }
        for(int col=0; col<n-row-1; col++){
            cout<<a<<" ";
            a++;
        }
        cout<<endl;
    }
}