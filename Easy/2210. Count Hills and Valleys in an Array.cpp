// Problem Link: https://leetcode.com/problems/count-hills-and-valleys-in-an-array/description/?envType=daily-question&envId=2025-07-27

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans=0,n=nums.size();
        for(int i=1;i<n-1;i++){
            if(nums[i]==nums[i+1])continue;
            int l=i-1,r=i+1;
            while(l && nums[l]==nums[i])l--;
            while(r<n && nums[r]==nums[i])r++;
            if((nums[l]>nums[i] && nums[r]>nums[i]) || (nums[l]<nums[i] && nums[r]<nums[i]))ans++;
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);