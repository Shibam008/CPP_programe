#include <iostream>
using namespace std ;

int setbit(int num,int k){
    int mask = 1 << k; // k=2 hole mask = 100,k=3 hole mask = 1000 and so on.
    int ans = num | mask;
    return ans;
}

int main(){
    int n,k;
    cout<<"Enter the number : ";
    cin>>n;
    cout<<"How many bit/bits do you want to shift ? : ";
    cin>>k;

    int value = setbit(n,k);

    cout<<"Number after setting k_th bit "<<value;

}