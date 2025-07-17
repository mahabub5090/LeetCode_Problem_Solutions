// Problem Link: https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/description/?envType=daily-question&envId=2025-07-17

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>>dp(k,vector<int>(k,0));
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int curr=nums[i]%k;
            for(int j=0;j<k;j++){
                dp[j][curr]=dp[curr][j]+1;
                ans=max(ans,dp[j][curr]);
            }
        }
        return ans;
    }
};

// Time Complexity : O((K^2)+(N*K)) => O(N^2);
// Space Complexity: O(k*k) => O(N^2);