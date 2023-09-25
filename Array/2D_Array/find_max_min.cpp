#include<iostream>
#include<limits.h>
using namespace std;

int maxnum(int arr[][3],int row,int col){
    int maxans = INT_MIN;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(arr[i][j]>maxans){
                maxans = arr[i][j];
            }
        }
    }
    return maxans;
}

int minnum(int arr[][3],int row,int col){
    int minans = INT_MAX;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(arr[i][j]<minans){
                minans = arr[i][j];
            }
        }
    }
    return minans;
}

int main (){
    int arr[][3]={
        {10,20,30},
        {30,52,60},
        {80,90,66}
    };
    int row = 3, col = 3;
    cout<<"Maximun number is : "<<maxnum(arr,row,col)<<endl;
    cout<<"Minimun number is : "<<minnum(arr,row,col)<<endl;
    
} 