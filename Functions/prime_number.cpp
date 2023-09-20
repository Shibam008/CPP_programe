#include <iostream>
using namespace std ;

bool checkprime(int num){
    for(int i=2; i<=(num-1); i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int number ;
    cout<<"Enter a positive intiger number : ";
    cin>> number;

    bool ans = checkprime(number);

    if(ans == true){
        cout << number << " is a prime number.";
    }
    else{ 
        cout << number << " is Not a prime number.";
    }

}