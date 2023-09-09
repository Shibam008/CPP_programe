#include<iostream>
using namespace std;
int main (){
    int n;
    cout << "Enter number of rows : ";
    cin >> n ;

    //for loop er modhye conditional part er range tai hochhe total value for that loop.

    for(int row=0; row<n; row++){ //total row = n
        //for space printing
        for(int col=0; col<n-row-1; col++){ //here total column = n-row-1
            cout << " " ; //one space 
        }
        for(int col=0; col<row+1; col++){   //here total column = row+1
            if(col==0 || col==(row+1)-1){    //for 0 based calculation total col 'X' hole [1st = 0 & last = X-1]
                cout << "* ";
            } 
            else{
                cout << "  ";
            }   
        }
        cout << endl;
    } 
    
}