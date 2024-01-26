#include<iostream>
#include<vector>
using namespace std;

int wavePrint_col_wise(vector<vector<int> > &arr){
    int row = arr.size();
    int col = arr[0].size();

    for(int col_index=0; col_index<col; col_index++){
        if(col_index % 2 == 0){
            for(int i=0; i<col; i++){  //top to bottom , when even column
                cout<<arr[i][col_index]<<" ";
            }
        }
        else{
            for(int i=row-1; i>=0; i--){ // bottom to top , when odd column
                cout<<arr[i][col_index]<<" ";
            }
        }
    }
}
int wavePrint_row_wise(vector<vector<int> > &arr){
    int row = arr.size();
    int col = arr[0].size();

    for(int row_index=0; row_index<row; row_index++){
        if(row_index % 2 == 0){
            for(int i=col-1; i>=0; i--){  // right to left , when even row
                cout<<arr[row_index][i]<<" ";
            }
        }
        else{
            for(int i=0; i<row; i++){ // left to right , when odd row
                cout<<arr[row_index][i]<<" ";
            }
        }
    }
}

int main(){
    vector<vector<int> >arr = {
        {10, 20, 30},
        {40, 50, 60},
        {80, 90, 100}
    };
    cout<<"Wave print column wise : "<<endl;
    wavePrint_col_wise(arr);
    cout<<endl;
    cout<<"Wave print row wise : "<<endl;
    wavePrint_row_wise(arr);

}