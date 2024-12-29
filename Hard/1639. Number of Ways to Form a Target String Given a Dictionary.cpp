// Problem Link: https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/description/

class Solution {
public:
    int mod=1e9+7;
    map<pair<int,int>,int>mp;
    int dfs(int i,int k,auto &vc,auto &t){
        if(i==t.size())return 1;
        if(k==vc.size())return 0;
        if(mp.count({i,k}))return mp[{i,k}];

        long long notTake=dfs(i,k+1,vc,t);
        long long take=(long long)vc[k][t[i]-'a']*dfs(i+1,k+1,vc,t)%mod;
        return mp[{i,k}]=(notTake+take)%mod; 
    }
    int numWays(vector<string>& words, string target) {
        vector<vector<int>>vc(words[0].size(),vector<int>(26,0));
        for(auto &c:words){
            for(int i=0;i<c.size();i++)vc[i][c[i]-'a']++;
        }
        return dfs(0,0,vc,target);
    }
};

// Time Complexity : O(N*M) => O(N^2);
// Space Complexity: O(N*M) => O(N^2);
// N is words.length and M is words[i].length;