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
    cout<<"Show prime numbers between 1 to ";
    cin>> number;

    for(int i=2; i<=number; i++){
        bool ans = checkprime(i);
        if(ans == true){
            cout<<i<<" ";
        }
    }

}