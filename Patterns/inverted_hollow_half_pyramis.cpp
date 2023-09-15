#include<iostream>
using namespace std ;

int main (){
    int n;
    cout << " Enter numbers of row :";
    cin >> n ;
    int x = 1;

    for (int row=0; row<n; row++){
        for(int col=row+1; col<=n; col++){
            if(row==0 || col==row+1 || col==n){
                cout << col << " ";
            }
            else{ 
                cout << "  ";
            }
        
            }
            cout<<endl;   
        }
        
    }
