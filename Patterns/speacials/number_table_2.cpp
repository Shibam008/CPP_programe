// 1 2 3 4 3 2 1
// 1 2 3   3 2 1
// 1 2       2 1
// 1           1
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter row number : ";
    cin>>n;

// first row
    for(int i=1; i<=n; i++){
        cout<<i<<" ";
    }
    for(int i = n-1; i>=1; i--){
        cout<<i<<" ";
    }
cout<<endl;

//second half
for(int row=0; row<(n-1); row++){

    for(int col=0; col< (n-1)-row; col++){
        cout<<col+1<<" ";
    }
    
    for(int col=0; col< (2*row+1); col++){
        cout<<"  ";
    }
    
    for(int col= (n-1)-row; col>=1; col--){
        cout<<col<<" ";
    }
    cout<<endl;
}

}