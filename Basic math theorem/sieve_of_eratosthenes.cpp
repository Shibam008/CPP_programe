#include <iostream>
#include<bits/stdc++.h>
using namespace std;

vector<bool> Seive_of_Era(int n){

    vector<bool> seive(n+1, true);
    seive[0] = seive[1] = false;

    for(int i=2; i<=sqrt(n); i++){  // instead of sqrt(n) we can use {i*i <= n}
        if(seive[i] == true){

            int j = i*i; // for overcoming redundency 

            while(j <= n){
                seive[j] = false;
                j = j+i;
            }
        }
    }
    return seive;
}
int main(){
    int num;
    cout<<"Enter range (0 - ?) : ";
    cin>>num;
    vector<bool> ans = Seive_of_Era(num);

    for(int i=0; i<=num; i++){
        if(ans[i] == true){
            cout<< i <<" ";
        }
    }
    return 0;
}
