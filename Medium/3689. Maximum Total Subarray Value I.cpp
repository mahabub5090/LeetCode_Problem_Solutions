// Problem Link: https://leetcode.com/problems/maximum-total-subarray-value-i/description/?envType=daily-question&envId=2026-06-09

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mx=*max_element(nums.begin(),nums.end());
        int mn=*min_element(nums.begin(),nums.end());
        return 1ll*k*(mx-mn);
    }
};

// Time Complexity : O(N) + O(N) => O(N);
// Space Complexity: O(1);