// Probblem Link: https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/description/?envType=daily-question&envId=2026-08-15

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int xr=0, zeroCnt=0;

        for(auto &c:nums){
            xr^=c;
            zeroCnt+=(c==0);
        }
        
        if(xr) return n;
        if(zeroCnt==n) return 0;

        return n-1;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);