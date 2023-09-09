#include<iostream>
using namespace std;
int main (){
    int n;
    cout<<"Enter number of rows: ";
    cin>>n;

// 1st part
    for(int row=0; row<n; row++){   
        for(int col=0; col<row+1; col++){
            cout<<"*";
        }
        for(int col=0; col<(2*n)-(2*row)-1; col++){
            cout<<" ";
        }
        for(int col=0; col<row+1; col++){
            cout<<"*";
        }
        cout<<endl;
    } 
// 2nd part     
    for(int row=0; row<(2*n)+1; row++){
        cout<<"*";
    }
}