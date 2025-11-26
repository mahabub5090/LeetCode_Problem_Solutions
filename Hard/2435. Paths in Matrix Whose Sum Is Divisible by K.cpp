// Problem Link: https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/description/?envType=daily-question&envId=2025-11-26

class Solution {
public:
    using ll=long long;
    int mod=1e9+7;

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<ll>>>dp(n+1,vector<vector<ll>>(m+1,vector<ll>(k)));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i==1 && j==1){
                    dp[i][j][grid[0][0]%k]=1;
                    continue;
                }

                int val=grid[i-1][j-1]%k;

                for(int l=0;l<k;l++){
                    int prevMod=(l-val+k)%k;
                    dp[i][j][l]=(dp[i-1][j][prevMod]+dp[i][j-1][prevMod])%mod;
                }
            }
        }
        return dp[n][m][0];
    }
};

// Time Complexity : O(N*M*K) => O(N^2); // Since k<=50;
// Space Complexity: O(N*M*K) => O(N^2);
