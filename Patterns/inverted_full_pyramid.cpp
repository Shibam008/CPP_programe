#include<iostream>
using namespace std;
int main (){
    int n;
    cout << "Enter number of rows : ";
    cin >> n ;

    for(int row=0; row<n; row++){
        //for space printing
        for(int col=0; col<row; col++){
            cout << " " ; //one space 
        }
        for(int col=0; col<n-row; col++){
            cout << "* " ;
        }
        cout << endl;
    } 
    
}