// Problem Link: https://leetcode.com/problems/count-elements-with-maximum-frequency/description/?envType=daily-question&envId=2025-09-22

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;int mx=0;
        for(auto &c:nums)mp[c]++,mx=max(mx,mp[c]);
        int ans=0;
        for(auto &c:mp)if(c.second==mx)ans+=mx;
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);