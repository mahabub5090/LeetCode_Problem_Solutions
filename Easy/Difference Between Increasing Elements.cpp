// Problem Link: https://leetcode.com/problems/maximum-difference-between-increasing-elements/description/?envType=daily-question&envId=2025-06-16

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans=-1;
        int mn=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                ans=max(ans,nums[i]-mn);
            }
            mn=min(mn,nums[i]);
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);