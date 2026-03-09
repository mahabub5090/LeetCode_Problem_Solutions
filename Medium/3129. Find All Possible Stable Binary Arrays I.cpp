// Problem Link: https://leetcode.com/problems/find-all-possible-stable-binary-arrays-i/description/?envType=daily-question&envId=2026-03-09

class Solution {
public:
    using ll=long long;

    int numberOfStableArrays(int zero, int one, int limit) {
        ll mod=1e9+7;
        vector<vector<vector<ll>>>dp(zero+1,vector<vector<ll>>(one+1,vector<ll>(2)));

        for(int i=0;i<=min(zero,limit);i++)dp[i][0][0]=1;
        for(int i=0;i<=min(one,limit);i++)dp[0][i][1]=1;

        for(int i=1;i<=zero;i++){
            for(int j=1;j<=one;j++){ 
                dp[i][j][0]=dp[i-1][j][0]+dp[i-1][j][1];
                if(i>limit)dp[i][j][0]-=dp[i-limit-1][j][1];
                dp[i][j][0]=(dp[i][j][0]%mod+mod)%mod;
                
                dp[i][j][1]=dp[i][j-1][0]+dp[i][j-1][1];
                if(j>limit) dp[i][j][1]-=dp[i][j-limit-1][0];
                dp[i][j][1]=(dp[i][j][1]%mod+mod)%mod;
            }
        }
        return (dp[zero][one][0]+dp[zero][one][1])%mod;
    }
};

// Time Complexity : O(min(zero,limit)) + O(min(one,limit)) + O(zero*one) => O(N^2);
// Space Complexity: O(zero*one*2) => O(N^2);