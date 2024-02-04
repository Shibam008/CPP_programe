/*
Problem statement -> " We have given two numbers and we have to find out the Quotent using binary search" (Given numbes coule be positive or negative)

Example = [ 24/12 = 2 ] , we have to return 2 (or the nearest integer)

* here 12 -> Divisor |||  24 -> Dividend ||| 2 -> Quotient
*****{ our search-space always lies between 0 to Dividend}*****

Formula (1) =>   (Quotient * Divisor) + Remainder = Dividend

Formula (2) =>   (Quotient * Divisor)  <= Dividend (**********)
*/

#include<bits/stdc++.h>
using namespace std;

int getQuotient(int dividend, int divisor){

    int s = 0;
    int e = dividend;
    int ans = -1;

    while(s <= e){
        
       int mid = s + (e-s)/2;

       if(mid * divisor == dividend){
           return mid;
       } 

       else if(mid * divisor < dividend){
           ans = mid ;
           s = mid + 1;
       }

       else{
           e = mid - 1;
       }
    }
    return ans;
}

int main(){
    int divisor, dividend;
    cout<<"Enter the value of Dividend : ";
    cin>>dividend;
    cout<<"Enter the value of Divisor : ";
    cin>>divisor;

    int ans = getQuotient(abs(dividend), abs(divisor)); // abs() = absolute function which convert -ve values into +ve value.

    if((divisor > 0 && dividend < 0) || (divisor < 0 && dividend > 0)){  // this line converts our ans into negative if given divisor or dividend is negative
        ans = 0 - ans;
    }

    cout << "Quotient = "<<ans<<endl;

}