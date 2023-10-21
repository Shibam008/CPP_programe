#include<iostream>
#include<algorithm>
using namespace std ;

bool twoSumMethod1(int arr[], int size, int X){
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if (arr[i]+arr[j] == X)
            return true;
        }
    }
    return false;
}

// Optimized solution with best time & space complexity . T.C -> O(nlogn)
bool twoSumMethod2(int arr[], int size, int X){
    sort(arr,arr+size); // we sort this using STL

    int l = 0;
    int h = size - 1;
    while(l<h){
        int csum = arr[l]+arr[h];
        if (csum == X) return true ;

        //if csum is greater than X it means, current pair is too large 
        //we have to move the low index to left to consider smaller pair
        else if (csum > X) h-- ;

        //if csum is less than X it means, current pair is too small
        //we have to move the low index to right to consider larger pair
        else l++ ;
        }
        return false;
    }


int main(){
    int arr[]={1,8,45,10,6,4};
    int size = 6;
    int target = 16;
    // sort(arr,arr+size);
    bool ans = twoSumMethod2(arr,size,target);
    cout<<ans; 

}