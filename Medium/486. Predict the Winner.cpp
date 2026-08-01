// Problem Link: https://leetcode.com/problems/predict-the-winner/description/?envType=daily-question&envId=2026-08-01

class Solution {
public:
    map<pair<int,int>, int> memo;
    int solve(int i,int j,auto &nums){
        if(i==j) return nums[i];
        if(memo.count({i,j})) return memo[{i,j}];

        int takeI=nums[i]-solve(i+1,j,nums);
        int takeJ=nums[j]-solve(i,j-1,nums);
        return memo[{i,j}]=max(takeI,takeJ);
    }

    bool predictTheWinner(vector<int>& nums) {
        return solve(0,nums.size()-1,nums)>=0;
    }
};

// Time Complexity : O(N^2);
// Space Complexity: O(N^2);