// Problem Link: https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/description/?envType=daily-question&envId=2025-04-27

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ans=0,n=nums.size();
        for(int i=0;i<n-2;i++){
            if((nums[i]+nums[i+2])*2==nums[i+1])ans++;
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);