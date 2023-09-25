#include<iostream>
using namespace std;
void diagonalsum(int arr[][4], int row, int col){
int sum = 0;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
        if(arr[i]==arr[j]){
        sum = sum+arr[j][i];
            }
        }
    }
    cout << "Diagonal sum -> "<<sum<<endl;
}

int main(){
    int arr[][4]={
        {10,20,30,40},
        {50,60,70,80},
        {15,25,35,45},
        {35,95,55,65}
    };
    
    int row=4, col=4; //we need square matrix for diagonal operation.

    diagonalsum(arr,row,col);
}