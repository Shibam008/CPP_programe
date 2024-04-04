#include <iostream>
using namespace std;

bool searching(int *arr, int size, int target, int index){
    
    if(index >= size){
        return false;
    }
    if(arr[index] == target){
        return true;
    }

    bool ans = searching(arr, size, target, index+1);
    return ans;
}
int main(){
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr)/sizeof(int);
    int target = 30;
    int ans = searching(arr, size, target, 0);
    cout << "Target found or not --> "<<ans<<endl;
}