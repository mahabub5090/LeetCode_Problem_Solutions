// Problem Link: https://leetcode.com/problems/count-the-number-of-fair-pairs/description/?envType=daily-question&envId=2025-04-19

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            int up=upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i])-nums.begin();
            int lw=lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i])-nums.begin();
            ans+=up-lw;
        }
        return ans;
    }
};

// Time Complexity : O(2*NlogN) => O(NlogN);
// Space Complexity: O(1);