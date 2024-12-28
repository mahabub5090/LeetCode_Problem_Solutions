// Problem Link: https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/submissions/1490788508/?envType=daily-question&envId=2024-12-28

class Solution {
public:
     int dp(auto &sums, int k, int idx, int rem, auto& memo) {
        if (rem==0)return 0;
        if (idx>=sums.size())return INT_MIN;

        if (memo[idx][rem]!=-1) {
            return memo[idx][rem];
        }

        int include=sums[idx]+dp(sums,k,idx+k,rem-1,memo);
        int exclude=dp(sums,k,idx+1,rem,memo);

        return memo[idx][rem]=max(include,exclude);
    }

    void dfs(auto& sums, int k, int idx, int rem, auto& memo, auto& indices) {
        if (rem==0)return;
        if (idx>=sums.size())return;

        int include=sums[idx]+dp(sums,k,idx+k,rem-1,memo);
        int exclude=dp(sums,k,idx+1,rem,memo);

        if (include>=exclude) {
            indices.push_back(idx);
            dfs(sums,k,idx+k,rem-1,memo,indices);
        } 
        else {
            dfs(sums,k,idx+1,rem,memo,indices);
        }
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size()-k+1;
        vector<int>sums(n,0);
        int windowSum=0;

        for(int i=0;i<k;i++) {
            windowSum+=nums[i];
        }
        sums[0]=windowSum;

        for(int i=k;i<nums.size();i++){
            windowSum=windowSum-nums[i-k]+nums[i];
            sums[i-k+1]=windowSum;
        }

        vector<vector<int>>memo(n,vector<int>(4,-1));

        vector<int>indices;
        dp(sums,k,0,3,memo);
        dfs(sums,k,0,3,memo,indices);

        return indices;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);