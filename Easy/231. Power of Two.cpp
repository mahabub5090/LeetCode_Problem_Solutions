// Problem Link: https://leetcode.com/problems/power-of-two/description/?envType=daily-question&envId=2025-08-09

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)return 0;
        int cnt=0;
        for(int i=0;i<32;i++)cnt+=(n&(1<<i))!=0;
        return cnt==1;     
    }
};

// Time Complexity : O(32) => O(1);
// Space Complexity: O(1);