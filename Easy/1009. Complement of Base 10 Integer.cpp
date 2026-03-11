// Problem Link: https://leetcode.com/problems/complement-of-base-10-integer/description/?envType=daily-question&envId=2026-03-11

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)return 1;
        int curr=1;
        while(n>=curr){
            n=n^curr;
            curr<<=1;
        }
        return n;
    }
};

// Time Complexity : O(logN);
// Space Complexity: O(1);
