// Problem Link: https://leetcode.com/problems/partition-equal-subset-sum/description/?envType=daily-question&envId=2025-04-07

class Solution {
public:
    vector<vector<int>>dp;
    bool backtrack(int i,int sum,int tt,auto &nums){
        if(i>=nums.size())return 0;
        if(sum>tt)return 0;
        if(sum==tt)return 1;

        if(dp[i][sum]!=-1)return dp[i][sum];

        int inc=backtrack(i+1,sum+nums[i],tt,nums);
        int skip=backtrack(i+1,sum,tt,nums);

        return dp[i][sum]=inc|skip;
    }
    bool canPartition(vector<int>& nums) {
        int tt=0;
        for(auto &c:nums)tt+=c;
        if(tt%2)return 0;
        int target=tt/2;
        dp.assign(nums.size()+1,vector<int>(target+1,-1));
        return backtrack(0,0,target,nums);
    }
};

// Time Complexity : O(N*target) => O(N^2);
// Space Complexity: O(N*target) => O(N^2);
// taeget is totalSum/2 of nums array.