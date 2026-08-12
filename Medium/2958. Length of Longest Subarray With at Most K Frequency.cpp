// Problem Link: https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/?envType=daily-question&envId=2026-08-12

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;

        int i=0, j=0, ans=1;
        while(j<n){
            mp[nums[j++]]++;

            while(mp[nums[j-1]]>k) mp[nums[i++]]--;
            ans=max(ans,j-i);
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);