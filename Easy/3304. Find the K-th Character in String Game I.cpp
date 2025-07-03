// Problem Link: https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/description/

// class Solution {
// public:
//     char kthCharacter(int k) {
//         string s="a";
//         for(int i=0;i<9;i++){
//             string s2="";
//             for(auto &c:s)s2+='a'+((c-'a'+1)%26);
//             s=s+s2;
//         }
//         return s[k-1];
//     }
// };

// Time Complexity : O(2^9) => O(512) => O(1);
// Space Complexity: O(2^9) => O(512) => O(1);

// Way : 2 =>

class Solution {
public:
    char kthCharacter(int k) {
        k--;
        int shift=0;
        while(k){
            int len=1;
            while(len*2<=k)len*=2;
            if(k>=len)k-=len,shift++;
            // if k>1e7 then,
            // if(k>=len)k-=len,shift++,shift%=26;
        }
        return 'a'+shift;
    }
};

// Time Complexity : O(logK) => log(N);
// Space Complexity: O(1);