// Problem Link: https://leetcode.com/problems/number-of-equivalent-domino-pairs/description/?envType=daily-question&envId=2025-05-04

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int>mp(100,0);
        int ans=0;
        for(auto &c:dominoes){
            int val=max(c[0],c[1])*10+min(c[0],c[1]);
            ans+=mp[val];
            mp[val]++;
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);