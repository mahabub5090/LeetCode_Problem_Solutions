// Problem Link: https://leetcode.com/problems/power-of-four/description/?envType=daily-question&envId=2025-08-15

class Solution {
public:
    bool isPowerOfFour(int n) {
        return n>0 && (n&(n-1))==0 && n%3==1;
    }
};

// Time Complexity : O(1);
// Space Complexity: O(1);

