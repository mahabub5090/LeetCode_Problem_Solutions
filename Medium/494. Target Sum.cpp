// Problem Link: https://leetcode.com/problems/target-sum/description/?envType=daily-question&envId=2024-12-26

class Solution {
public:
    map<pair<int,int>,int>mp;
    int backtrack(int i,int currSum,auto &nums,int target){
        if(mp.count({i,currSum}))return mp[{i,currSum}];
        if(i==nums.size())return currSum==target;
        return mp[{i,currSum}]=backtrack(i+1,currSum+nums[i],nums,target)+backtrack(i+1,currSum-nums[i],nums,target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return backtrack(0,0,nums,target);
    }
};

// Time Complexity : O(N*M);
// Space Complexity: O(N*M);
// M is the total sum of nums vector.