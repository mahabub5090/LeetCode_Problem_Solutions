// Problem Link: https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/description/?envType=daily-question&envId=2025-02-03

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans=0,i=0,j=1,n=nums.size();
        while(j<n){
            if(nums[j]>nums[j-1])j++;
            else ans=max(ans,j-i),i=j,j++;
        }
        ans=max(ans,j-i);
        i=0,j=1;
        while(j<n){
            if(nums[j]<nums[j-1])j++;
            else ans=max(ans,j-i),i=j,j++;
        }
        ans=max(ans,j-i);
        return ans;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(1);