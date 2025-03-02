// Problem Link: https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/description/?envType=daily-question&envId=2025-03-02

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int>mp;
        for(auto &c:nums1)mp[c[0]]+=c[1];
        for(auto &c:nums2)mp[c[0]]+=c[1];
        vector<vector<int>>ans;
        for(auto &c:mp)ans.push_back({c.first,c.second});
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// Time Complexity : O((N+M)log(N+M)) => O(NlogN);
// Space Complexity: O(2*(N+M)) => O(N);