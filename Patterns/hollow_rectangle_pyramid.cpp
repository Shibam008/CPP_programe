#include<iostream>
using namespace std ;

int main (){ 
    int n ;
    cout<<"Enter numbers of rows: ";
    cin >> n;
    for (int row = 0 ; row<n ; row++){
        for(int col = 0 ; col<n ; col++){
            if(row == 0 || row == n-1){
                cout << "* ";
            }
            else{
                if (col == 0||col == n-1){
                    cout << "* ";  
                }
                else{
                    cout << "  " ; //take tow spaces.
                }
                
            }
        }
        cout << endl;
    }
    
    return 0;
}