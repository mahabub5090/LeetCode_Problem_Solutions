// Problem Link: https://leetcode.com/problems/rank-transform-of-an-array/submissions/1409212335/?envType=daily-question&envId=2024-10-02
// Problem Link: https://leetcode.com/problems/rank-transform-of-an-array/description/?envType=daily-question&envId=2026-07-12

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> st(arr.begin(),arr.end());
        unordered_map<int,int> mp;
        int cnt=1;
        for(auto &c:st) mp[c]=cnt++;
        vector<int> ans;
        for(auto &c:arr) ans.push_back(mp[c]);
        return ans;
    }
};

// Time Complexity : O(NlogN) + O(N) + O(N) => O(NlogN);
// Space Complexity: O(N) + O(N) + O(N) => O(N);