// Problem Link: https://leetcode.com/problems/ones-and-zeroes/description/?envType=daily-question&envId=2025-11-11

class Solution {
public:
    map<tuple<int,int,int>,int>dp;  

    int backtrack(int i,int cnt,int cnt2,auto &strs,auto &mp,int m,int n){
        if(i==strs.size())return 0;
        if(dp.count({i,cnt,cnt2}))return dp[{i,cnt,cnt2}];
        
        int c=mp[strs[i]];
        int c2=strs[i].size()-c;

        int skip=backtrack(i+1,cnt,cnt2,strs,mp,m,n);
        int take=0;
        if(cnt+c<=m && cnt2+c2<=n)take=1+backtrack(i+1,cnt+c,cnt2+c2,strs,mp,m,n);

        return dp[{i,cnt,cnt2}]=max(take,skip);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        unordered_map<string,int>mp;
        for(auto &c:strs){
            mp[c]=count(c.begin(),c.end(),'0');
        }
        return backtrack(0,0,0,strs,mp,m,n);
    }
};

// Time Complexity : O(L*N*M) => O(N^3);
// Space Complexity: O(L*N*M) => O(N^3);