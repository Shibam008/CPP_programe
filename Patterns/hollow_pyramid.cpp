#include<iostream>
using namespace std;
int main (){
    int n;
    cout << "Enter number of rows : ";
    cin >> n ;

    //ekhane FULL_PYRAMID er program likhe if-else use krte hbe .

    for(int row=0; row<n; row++){ //total row = n
        //for space printing
        for(int col=0; col<n-row-1; col++){ //here total column = n-row-1
            cout << " " ; //one space 
        }
        for(int col=0; col<row+1; col++){   //here total column = row+1
            if(col==0 || col==(row+1)-1){    
                cout << "* ";
            } 
            else{
                cout << "  ";
            }   
        }
        cout << endl;
    } 
    
}