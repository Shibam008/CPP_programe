#include<iostream>
using namespace std;
int moveleft(int nums[], int size){
    int l=0, h = size-1;

    while(l<h){
        if(nums[l]<0) l++;
        else if(nums[h]>0) h--;
        else{
            swap(nums[l], nums[h]);
        }
    }
}

int main(){
    int nums[]={1,3,-5,8,-9,7,-2};
    int size = sizeof(nums)/sizeof(int);

    moveleft(nums, size);
    for(int i=0; i<size; i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}