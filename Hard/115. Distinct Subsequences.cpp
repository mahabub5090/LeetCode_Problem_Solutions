// Problem Link: https://leetcode.com/problems/distinct-subsequences/description/?envType=daily-question&envId=2026-09-06

class Solution {
public:
    int backtrack(int i, int j, auto &s, auto &t, auto &dp){
        if(j==t.size()) return 1;
        if(i==s.size()) return 0;;
        if(dp[i][j]!=-1) return dp[i][j];

        int same=(s[i]==t[j]? backtrack(i+1,j+1,s,t,dp): 0);

        return dp[i][j]= same + backtrack(i+1,j,s,t,dp);
    }


    int numDistinct(string s, string t) {
        int n=s.size(), m=t.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return backtrack(0, 0, s, t, dp);
    }
};

// Time Complexity : O(N*M) => O(N^2);
// Space Complexity: O(N*M) => O(N^2);
// N = s.size(), M = t.size() and 1 <= N, M <= 1000;