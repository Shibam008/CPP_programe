#include<iostream>
using namespace std ;

int main (){
    int n;
    cout << " Enter numbers of row :";
    cin >> n ;

    for (int row=0; row<n; row++){
        for(int col=0; col<row+1; col++){
            if(col==0 || col==(row+1)-1 || row == n-1){  // last row te sb value print hbe.
                cout << col+1 <<" ";
            }
            else{
                cout << "  ";
            }
            
        }
        cout<<endl;
    }
}