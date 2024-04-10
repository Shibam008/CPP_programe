

// Method name --> include-exclude pattern (********)imp
#include <iostream>
using namespace std;

void findSubsequences(string str, string output, int index){
    //base cse
    if(index >= str.length()){
        // we get the ans at this point
        cout << "-> " << output << endl;
        return;
    }

    char ch = str[index];

//---------------------------------------------------------
    // //exclude
    // findSubsequences(str, output, index+1);

    // //include
    // output.push_back(ch);
    // findSubsequences(str, output, index+1);

//---------------------------------------------------------

    //include
    output.push_back(ch);
    findSubsequences(str, output, index+1);

    //exclude
    output.pop_back();
    findSubsequences(str, output, index+1);
    
}

int main(){
    string str = "abc";
    string output = "";
    int index = 0;
    findSubsequences(str, output, index);
}