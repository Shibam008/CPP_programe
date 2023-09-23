#include<iostream>
using namespace std;
int main(){
    int arr[2][3];
    int row=2,col=3;

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout << "enter the value of index ("<<i<<","<<j<<") : ";
            cin >> arr[i][j];
            }
        }

}