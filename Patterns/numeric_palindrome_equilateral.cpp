#include <iostream>
using namespace std ;

int main() {
    int n ; 
    cout<<"enter row num : ";
    cin >> n ;
    
    for(int row=0; row<n; row++){
        for(int col=0; col<(n-row)-1; col++){
            cout << "  ";
        }
        for(int col=1; col<=row+1; col++){
            cout << col <<" ";
        }
        for(int col=(row+1)-1; col>=1; col--){
            cout << col <<" ";
        }
        cout << endl;
        
    }

    return 0;
}