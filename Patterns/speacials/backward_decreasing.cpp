#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter number of rows : ";
    cin>>n;
    for(int row=0; row<n; row++){
        for(int col = n-row; col>=1; col--){
            cout<<col<<" "; // cout<<char(col+64)<<" ";
        }
        cout<<endl;
    }
}