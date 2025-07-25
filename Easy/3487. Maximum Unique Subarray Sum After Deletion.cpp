// Problem Link: https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/description/?envType=daily-question&envId=2025-07-25

class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans=0,mx=INT_MIN;
        for(auto &c:nums){
            mx=max(mx,c);
            if(c<=0 || mp[c])continue;
            ans+=c;
            mp[c]++;
        } 
        return ans==0?mx:ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);
