#include<iostream>
using namespace std;

bool searching(int arr[][3],int row, int col, int target){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(arr[i][j]==target){
                return true;
            }
        }
    }
    return false;
}

int main (){
    int arr[][3]={
        {10,20,30},
        {30,52,60},
        {80,90,66}
    };
    int row = 3, col = 3;
    int target;
    cout<<"enter target value : ";
    cin >> target;
        
    cout << "found or not : " << searching(arr,row,col,target) <<" [1->Found & 0->Not found]";
    //as it is a boolean function, it will return 1 for true || return 0 for false.
} 