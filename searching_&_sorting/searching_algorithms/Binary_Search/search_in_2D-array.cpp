#include<bits/stdc++.h>
using namespace std;
bool search(vector<vector<int>> &matrix, int x){
    
    int row = matrix.size();
    int col = matrix[0].size();
    int n = row * col ; // total number of element.

    int s = 0;
    int e = n-1;

    while(s <= e){

        int mid = s + (e-s)/2;

        int rowIndex = mid / col;
        int colIndex = mid % col;
        int currNumber = matrix[rowIndex][colIndex];
// performing binary search 
        if(currNumber == x) 
        return true;
        else if(x > currNumber) s = mid + 1; // go right 
        else e = mid - 1; // go left
    }
    return false;
}
int main(){
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target;
    cout << "Enter target value for searching : ";
    cin>>target;
    bool ans = search(matrix, target);
    
    if(ans == 1){
        cout<<"Target found"<<endl;
    }
    else cout<<"Target not found"<<endl;

}