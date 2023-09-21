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
    int index = 0;

    while(ZeroCount--){
        array[index]=0;
        index++;
    }
    while(OneCount--){
        array[index]=1;
        index++;
    }
}


int main(){
    int numbers[]={0,0,0,1,1,1,0,1,0,1,0,1}; //1=0= 6
    int size = 12;
        countZeroOne(numbers,size);

        for(int i=0; i<size; i++){
            cout << numbers[i] << " " ;
        }
    
}