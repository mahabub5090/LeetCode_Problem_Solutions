// Problem Link: https://leetcode.com/problems/count-commas-in-range/description/?envType=daily-question&envId=2026-09-08

class Solution {
public:
    int countCommas(int n) {
        return max(n-999, 0);
    }
};

// Time Complexity : O(1);
// Space Complexity: O(1);