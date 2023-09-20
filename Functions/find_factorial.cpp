#include <iostream>
using namespace std ;

int factorial(int num){
    int fact = 1;
    for(int i=1; i<=num; i++){
        fact = fact*i;
    }
    return fact;
}

int main(){
    int number;
    cout<<"enter a number for finding factorial : ";
    cin>>number;

    int ans = factorial(number);
    cout<<"Factorial of "<<number<< " is "<<ans;

}