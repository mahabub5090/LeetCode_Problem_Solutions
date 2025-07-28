// Problem Link: https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/description/?envType=daily-question&envId=2024-10-18
// Problem Link: https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/description/?envType=daily-question&envId=2025-07-28

class Solution {
public:
    void dfs(int i,auto &vc,int cor,int mor,int &cnt){
        if(i==vc.size())return;
        if((cor|vc[i])==mor)cnt++;
        dfs(i+1,vc,cor|vc[i],mor,cnt);
        dfs(i+1,vc,cor,mor,cnt);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int mor=0;
        for(auto &c:nums)mor|=c;
        int cnt=0;
        dfs(0,nums,0,mor,cnt);
        return cnt;
    }
};

// Time Complexity : O(2^N);
// Space Complexity: O(N); // for call stack;

// Way: 2 =>

class Solution {
public:
    vector<vector<int>>memo;
    int backtrack(int i,int xr,int maxOr,auto &nums){
        if(i==nums.size())return xr==maxOr;
        if(memo[i][xr]!=-1)return memo[i][xr];
        
        int take=backtrack(i+1,xr|nums[i],maxOr,nums);
        int skip=backtrack(i+1,xr,maxOr,nums);
        return memo[i][xr]=take+skip;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr=0;
        for(auto &c:nums)maxOr|=c;
        memo.assign(nums.size(),vector<int>(maxOr+1,-1));
        return backtrack(0,0,maxOr,nums);
    }
};

// Time Complexity : O(N*maxOr) => O(N^2);
// Space Complexity: O(N*maxOr) => o(N^2);