#include<iostream>
#include<vector>
using namespace std;

int peak_element(vector<int> &arr){
    int s = 0; 
    int e = arr.size()-1;

    while(s < e){
        int mid = s + (e-s)/2;

        if(arr[mid] < arr[mid+1]){
              s = mid+1;
        } 
        else{ //arr[mid] > arr[mid+1]
            e = mid; 
            }   
        }
        return s; // we can return s or e . coz at last time s & e will point to the same element and that's our peak element.
}

int main(){
    vector<int> arr = {10, 20, 30, 90, 100, 50, 40, 30};
    int index = peak_element(arr);
    cout<<"Peak element in the mountain array is = "<<arr[index]<<endl;
}

// In this problem First we have to divide this array into two part . Part A and Part B .
// Now IN part A there are {10, 20, 30} , and this is completely visible that || arr[i] < arr[i+1] || .
//We have left with PEAK element and Part B.
//IN part B there are {70, 50, 40, 30}, and this is completely visible that || arr[i] > arr[i+1] || .

//when we calculate mid, if we stay in part A our peak element should stay in right side that's why we shift our start(s) to the right . (s = mid + 1);

// else there would be two cases - 
/*

Case 1 - Our mid is pointing Part B
case 2 - Our mid is pointing to the PEAK element.

so we generally know if our mid is pointing to Part B our Peak element Should be on Left side so we have to move our End(e) to left. But here's the twist if we update {e = mid - 1} for going left our PEAK could lost. That's why we update    {e = mid} so that if our mid, point to PEAK-element, we won't lost.

*/

// ***** most important point is as we update {e = mid} instead of updating {e = mid - 1} we have to give that loop condition (s < e) rather than (s <= e). If we give this condition (s <= e) our programe will be trapped into Infinite loop.


