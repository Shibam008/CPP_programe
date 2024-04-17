#include<iostream>
using namespace std;

int x = 2; // GLOBAL

int main(){
    int x = 5;
    cout << x << endl;   // local or mos recent value will be preffered

    cout << ::x << endl; // accessing global variable using (::)
}