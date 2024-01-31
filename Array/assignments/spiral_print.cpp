#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// Run this code on Leetcode 

vector<int> spiralPrint(vector<vector<int>> &matrix){

    vector<int>ans;
    
    int m = matrix.size();  // row
    int n = matrix[0].size();  // column

    int starting_row = 0;
    int ending_col = n-1;
    int ending_row = m-1;
    int starting_col = 0;

    int total_element = m*n;

    int count = 0;
    while(count < total_element){
        //print starting row
        for(int i=starting_col; i<=ending_col && count<total_element; i++){
            ans.push_back(matrix[starting_row][i]);
            count++;
        }
        starting_row++;

        //print ending column
        for(int i=starting_row; i<=ending_row && count<total_element; i++){
            ans.push_back(matrix[i][ending_col]);
            count++;
        }
        ending_col--;

        //print ending row
        for(int i=ending_col; i>=starting_col && count<total_element; i--){
            ans.push_back(matrix[ending_row][i]);
            count++;
        }
        ending_row--;

        //print starting column
        for(int i=ending_row; i>=starting_row && count<total_element; i--){
            ans.push_back(matrix[i][starting_col]);
            count++;
        }
        starting_col++;
    }
    return ans;
}

int main(){
    vector<vector<int>> matrix = {
        {1, 2, 3, 4, 5, 6},
        {7, 8, 9, 10, 11, 12},
        {3, 9, 8, 14, 15, 74},
        {21, 25, 45, 62, 32, 44},
        {4, 5, 21, 45, 58, 41}
    };

    vector<int> result = spiralPrint(matrix);

    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0;
}