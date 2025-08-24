// Problem Link: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/?envType=daily-question&envId=2025-08-24

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0,i=0,j=0,n=nums.size();
        int cnt=0;
        while(j<n){
            if(nums[j++]==0)cnt++;
            while(cnt>1)cnt-=nums[i++]==0;
            ans=max(ans,j-i-1);
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);