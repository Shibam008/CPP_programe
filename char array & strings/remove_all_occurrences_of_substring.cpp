// Leetcode : 1910 (medium)


/*
Points :
    1. while(substring exists in main string){
        remove
    }
    
*/


#include<iostream>
using namespace std;

string removeSubstringOccurence(string str, string subStr){
        while(str.find(subStr) != string::npos){
            str.erase(str.find(subStr), subStr.length());
        }
        return str;

}

int main(){
    string str, subStr;
    cout<<"Enter String : ";
    cin>>str;
    cout<<"Enter Sub-String : ";
    cin>>subStr;

    cout << "Final ans : " << removeSubstringOccurence(str, subStr) <<endl;
    return 0;
}