#include <iostream>
using namespace std ;

void checknumber(int num){      // ekhane just checking hochhe kono value return krbe na .
    if(num%2==0){
        cout<<num<<" is a Even number.";
    }
    else{
        cout<<num<<" is a Odd number.";
    }
}

int main(){
    int x;
    cout<<"enter a number : ";
    cin>>x;
    
    checknumber(x);  //ekhane kono ans return hobe na .

}