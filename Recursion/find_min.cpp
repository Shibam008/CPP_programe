#include<iostream>
#include <limits.h>
using namespace std;

void findMin(int *arr, int size, int &mini, int index){

    if(index >= size){
        return;
    }

    mini = min(mini, arr[index]);
    
    findMin(arr, size, mini, index+1);

}
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr)/sizeof(int);
    int mini = INT_MAX;
    findMin(arr, size, mini, 0);
    cout << " Min ans = " << mini;


}