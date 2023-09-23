#include <iostream>
using namespace std ;
void printarray(int arr[][3], int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main (){
    int arr[][3]={
        {12,28,3},
        {55,3,67}
    };
    int row=2,col=3;
    printarray(arr,row,col);
    

}