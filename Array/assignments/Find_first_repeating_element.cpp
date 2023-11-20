#include<iostream>
#include<unordered_map>
using namespace std;
int findDuplicate(int arr[], int size){

    unordered_map<int, int>newmap; //using hashmap.
    for(int i=0; i<size; i++){
        newmap[arr[i]]++;
    }
    for(int i=0; i<size; i++){
        if(newmap[arr[i]] > 1)
        return i+1; // as we want to to see the index as 1 based insted of 0 based index.
    }
    return -1;

}
int main(){
    int arr[]={1,2,3,4,5,3,6};
    int size = sizeof(arr)/sizeof(int);
    int ans = findDuplicate(arr,size);
    cout<<"index of first repeating element in (1 based indexing) is = "<<ans;

    
}