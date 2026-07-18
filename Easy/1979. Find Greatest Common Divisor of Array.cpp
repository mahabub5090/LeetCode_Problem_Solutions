// Problem Link: https://leetcode.com/problems/find-greatest-common-divisor-of-array/description/?envType=daily-question&envId=2026-07-18

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn=INT_MAX, mx=INT_MIN;
        for(auto &c:nums) mn=min(mn,c), mx=max(mx,c);
        return __gcd(mn,mx);
    }
};

// Time Complexity : O(N) + O(logM) => O(N + logM);
// Space Complexity: O(1);
// M = max(nums[i]);