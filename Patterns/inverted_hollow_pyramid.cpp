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
        //ekhane inverted full pyramid er programe likhe if-else use krte hbe
        for(int col=0; col<n-row; col++){   
            if(col==0 || col==(n-row)-1){   
                cout << "* ";
            } 
            else{
                cout << "  ";
            }   
        }
        cout << endl;
    } 
    
}