// Problem Link: https://leetcode.com/problems/find-missing-and-repeated-values/description/?envType=daily-question&envId=2025-03-06

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        map<int,int>mp;
        int mx=0;
        for(auto &c:grid)for(auto &cc:c)mx=max(mx,cc),mp[cc]++;
        int twice,miss=0;
        for(int i=1;i<=mx;i++){
            if(mp[i]==0)miss=i;
            if(mp[i]==2)twice=i;
        }
        return {twice,miss?miss:mx+1};
    }
};

// Time Complexity : O(N*N) + O(N) => O(N^2);
// Space Complexity: O(N*N) => O(N^2);