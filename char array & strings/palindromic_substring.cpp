

// leetcode 647 medium

// class Solution {
// public:
//     int expand(string s, int i, int j) {
//         int count = 0;
//         while(i >= 0 && j < s.length() && s[i] == s[j]) {
           
//                 count++;
//                 i--;  
//                 j++;
//                 // opposite direction(outwards) of two pointer approach
        
//         }
//         return count;
//     }

//     int countSubstrings(string s) {
//         int totalans = 0;
//         // consider every index as center
//         for(int i=0; i<s.length(); i++) {
            
//             //Odd
//             int j = i;
//             int oddAns = expand(s, i, j);

//             //Even
//             j = i+1;
//             int evenAns = expand(s, i, j);

//             totalans = totalans + oddAns + evenAns;
//         }
//         return totalans;
//     }
// };

