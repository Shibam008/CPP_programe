#include<iostream>
using namespace std;
int main (){
    int n;
    cout << "Enter number of rows : ";
    cin >> n ;
//for upper full pyramid
    for(int row=0; row<n; row++){
        //for space printing
        for(int col=0; col<n-row-1; col++){
            cout << " " ; //one space 
        }
        for(int col=0; col<row+1; col++){
            cout << "* " ;
        }
        cout << endl;
    } 
//for lower full pyramid
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