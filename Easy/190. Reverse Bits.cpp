// Problem Link: https://leetcode.com/problems/reverse-bits/description/?envType=daily-question&envId=2026-02-16

// class Solution {
// public:
//     int reverseBits(int n) {
//         string s="";
//         while(s.size()!=32)s+='0'+(n%2),n/=2;
       
//         int ans=0;
//         for(auto &c:s){
//             ans*=2;
//             ans+=(c=='1');
//         }
//         return ans;
//     }
// };

// // Time Complexity : O(2*32) => O(1);
// // Space Complexity: O(32) => O(1);

// Way : 2 =>

class Solution {
public:
    int reverseBits(int n) {
        int ans=0;
        for(int i=0;i<32;i++){
            ans*=2;
            ans+=(n%2);
            n>>=1;
        }
        return ans;
    }
};

// Time Complexity : O(32) => O(1);
// Space Complexity: O(1);
