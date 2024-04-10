#include<iostream>
using namespace std;

void printDigits(int n){

    if(n == 0){
        return;
    }

    int digit = n % 10;
    n = n/10;

    printDigits(n);

    cout << digit << endl;
    
}
int main(){
    int num;
    cout << "Enter a number : ";
    cin >> num;
    printDigits(num);
}