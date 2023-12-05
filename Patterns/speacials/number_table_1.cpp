//1 2 3 4 5 6 7
//1 2 3   5 6 7
//1 2       6 7
//1           7
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter number of rows : ";
    cin>>n;
// first row 
    for(int i=1; i<=(2*n)-1; i++){
        cout<<i<<" ";
    }
    cout<<endl;

//second half

    for(int row=0; row < (n-1); row++){
        int a=1; // we have to initialize this variable inside the loop.
        for(int col=0; col< (n-1)-row; col++){
            cout<<a<<" ";
            a++;
        }
        for(int col=0; col<(2*row)+1; col++){
            cout<<"  ";
            a++;
        }
        for(int col=0; col< (n-1)-row; col++){
            cout<<a<<" ";
            a++;
        }
        cout<<endl;
    }
}