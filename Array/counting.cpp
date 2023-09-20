//   count 0's and 1's
#include<iostream>
using namespace std ;

int countZeroOne(int array[],int size){
    int ZeroCount = 0;
    int OneCount = 0;
    for(int i=0; i<size; i++){
        if(array[i]==0){
            ZeroCount++;
        }
        if(array[i]==1){
            OneCount++;
        }
    }
    cout<<"zerocount :"<<ZeroCount<<endl;
    cout<<"onecount :"<<OneCount<<endl;
}

int main(){
    int numbers[]={0,0,0,1,1,1,0,1,0,1,0,1}; //1=0= 6
    int size = 12;
        countZeroOne(numbers,size);
    
}