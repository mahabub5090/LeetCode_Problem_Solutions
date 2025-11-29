// Problem Link: https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/description/?envType=daily-question&envId=2025-11-29

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum=0;
        for(auto &c:nums)sum+=c;
        return sum%k;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);