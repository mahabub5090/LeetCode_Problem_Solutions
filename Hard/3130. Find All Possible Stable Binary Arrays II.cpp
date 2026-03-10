// Problem Link: https://leetcode.com/problems/find-all-possible-stable-binary-arrays-ii/?envType=daily-question&envId=2026-03-10

class Solution {
public:
    using ll=long long;

    int numberOfStableArrays(int zero, int one, int limit) {
        ll mod=1e9+7;
        vector<vector<vector<ll>>>dp(zero+1,vector<vector<ll>>(one+1,vector<ll>(2)));

        for(int i=0;i<=zero;i++){
            for(int j=0;j<=one;j++){
                for(int lb=0;lb<=1;lb++){
                    if(i==0){
                        dp[i][j][lb]=(lb && j<=limit);
                    }
                    else if(j==0){
                        dp[i][j][lb]=(lb!=1 && i<=limit);
                    }
                    else if(lb==0){
                        dp[i][j][lb]=dp[i-1][j][0]+dp[i-1][j][1];
                        if(i>limit)dp[i][j][lb]-=dp[i-limit-1][j][1];
                    }
                    else{
                        dp[i][j][lb]=dp[i][j-1][0]+dp[i][j-1][1];
                        if(j>limit)dp[i][j][lb]-=dp[i][j-limit-1][0];
                    }

                    dp[i][j][lb]=(dp[i][j][lb]%mod+mod)%mod;
                }
            }
        }
        return (dp[zero][one][0]+dp[zero][one][1])%mod;
    }
};

// Time Complexity : O(zero*one) => O(N^2);
// Space Complexity: O(zero*one*2) => O(N^2);