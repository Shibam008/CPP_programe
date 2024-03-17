#include<iostream>
using namespace std;

string removeAdjacent(string s) {
    string ans = "";
    int index = 0;

    while(index < s.length()) {
        // checking right most element in 'ans' string with 's' string
        if(ans.length() > 0 && ans[ans.length() - 1] == s[index]) {
            ans.pop_back(); // remove same elements if exist
        }
        else {
            ans.push_back(s[index]);  // inserting unique one 
        }
        index++;
    }
    return ans;
}

int main() {
    string value;
    cout << "Enter any string: ";
    cin >> value;
    string final_ans = removeAdjacent(value);
    cout << "After Removing Adjacent duplicate elements, final string: " << final_ans;
    return 0;
}
