// Problem Link: https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/description/?envType=daily-question&envId=2026-01-24

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0,n=nums.size();
        for(int i=0;i<n/2;i++)ans=max(ans,nums[i]+nums[n-1-i]);
        return ans;
    }
};

// Time Complexity : O(NlogN) + O(N/2) => O(NlogN);
// Space Complexity: O(1);