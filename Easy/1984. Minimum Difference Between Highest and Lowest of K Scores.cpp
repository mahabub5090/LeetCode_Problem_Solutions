// Problem Link: https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/description/?envType=daily-question&envId=2026-01-25

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=nums[n-1]-nums[0];
        for(int i=k-1;i<n;i++)ans=min(ans,nums[i]-nums[i-k+1]);
        return ans;
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(1);