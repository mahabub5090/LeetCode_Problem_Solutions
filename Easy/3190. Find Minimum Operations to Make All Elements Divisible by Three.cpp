// Problem Link: https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/description/?envType=daily-question&envId=2025-11-22

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans=0;
        for(auto &c:nums)ans+=min(c%3,3-c%3);
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);