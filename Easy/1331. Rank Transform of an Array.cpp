// Problem Link: https://leetcode.com/problems/rank-transform-of-an-array/submissions/1409212335/?envType=daily-question&envId=2024-10-02

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int>st;for(auto &c:arr)st.insert(c);
        map<int,int>mp;
        int j=1;
        for(auto &c:st){
            mp[c]=j++;
        }
        vector<int>ans;
        for(auto &c:arr)ans.push_back(mp[c]);
        return ans;
    }
};

// Time Complexity : O(3*N) => O(N);
// Space Complexity: O(3*N) => O(N);