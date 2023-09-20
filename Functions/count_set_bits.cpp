#include <iostream>
using namespace std ;

int countSetBits(int num){
    int count = 0;

    while(num>0){
    int lastbit = (num & 1);
    if(lastbit == 1) 
    count++;
        num = (num >> 1) ; // right shift for skipping used last bit .
    }
    return count;
}

int main(){
    int n;
    cout<<"Enter a number for counting set bits : ";
    cin >> n;

    int setbits = countSetBits(n);
    cout<<"Set bit/bits of "<<n<<" is/are : " << setbits;
    

}