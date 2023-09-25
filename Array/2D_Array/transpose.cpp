#include<iostream>
using namespace std;
int printarray(int arr[][4], int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int transpose(int arr[][4], int row, int col){
    for(int i=0; i<row; i++){
        for(int j=i; j<col; j++){
            swap(arr[i][j],arr[j][i]);
        }
        cout<<endl;
    }
}

int main(){
    int arr[][4]={
        {10,20,30,40},
        {50,60,70,80},
        {15,25,35,45},
        {35,95,55,65}
    };
    
    int row=4, col=4; //we need square matrix for diagonal operation.
    cout<< endl <<"Given array : "<< endl;
    printarray(arr,row,col);

    cout<< endl <<"Doing transpose";
    transpose(arr,row,col);

    cout<<"Transpose of given array : "<< endl;
    printarray(arr,row,col);
    cout<<endl;
    
}