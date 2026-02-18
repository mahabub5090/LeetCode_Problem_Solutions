// Problem Link: https://leetcode.com/problems/binary-number-with-alternating-bits/description/?envType=daily-question&envId=2026-02-18

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev=n&1;
        n>>=1;
        while(n){
            int bit=n&1;
            if(bit==prev)return 0;
            prev=bit;
            n>>=1;
        }
        return 1;
    }
};

// Time Complexity : O(32) => O(1);
// space Complexity: O(1);