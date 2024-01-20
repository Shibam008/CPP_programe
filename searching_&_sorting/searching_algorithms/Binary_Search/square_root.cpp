#include<iostream>
using namespace std;

int mysqrt(int x){
    int s = 0;
    int e = x;
    int ans = 0;
    while(s <= e){
        long long int mid = s + (e-s)/2;
        if(mid*mid == x){   // predicate function , for checking if mid is answer.
            return mid;
        }
        else if(mid*mid < x){
             ans = mid;
             s = mid + 1;
        }
        else{
            e = mid - 1;
        }   
    }
    return ans;
}

int main(){
    int x;
    cout<<"Enter a value to get the square root : "<<endl;
    cin>>x;
    int ans = mysqrt(x);
    cout<<"Square root of "<<x<<" is = "<<ans<<endl;
}