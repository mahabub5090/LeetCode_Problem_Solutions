// Problem Link: https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/description/?envType=daily-question&envId=2024-09-14

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        int ans=0,cnt=0;
        for(auto &c:nums){
            if(c==mx)cnt++;
            else cnt=0;
            ans=max(ans,cnt);
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);