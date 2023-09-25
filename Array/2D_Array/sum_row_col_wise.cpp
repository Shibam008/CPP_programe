#include<iostream>
using namespace std;

void rowwisesum(int arr[][4], int row, int col){

    for(int i=0; i<row; i++){
        int sum=0;
        for(int j=0; j<col; j++){
            sum = sum+arr[i][j];
        }
        cout << "Row wise sum -> "<<sum<<endl;
    }
}

void colwisesum(int arr[][4], int row, int col){

    for(int i=0; i<col; i++){
        int sum = 0;        
        for(int j=0; j<row; j++){
            sum = sum+arr[j][i];
        }
        cout << "Column wise sum -> "<<sum<<endl;
    }
}

int main(){
    int arr[][4]={
        {10,20,30,40},
        {50,60,70,80},
        {15,25,35,45}
    };
    int row=3, col=4;

    rowwisesum(arr,row,col);
    colwisesum(arr,row,col);
}