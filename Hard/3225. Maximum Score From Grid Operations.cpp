// Problem Link: https://leetcode.com/problems/maximum-score-from-grid-operations/description/?envType=daily-question&envId=2026-04-29

class Solution {
public:
    using ll = long long int;

    long long maximumScore(vector<vector<int>>& grid) {
        int n=grid[0].size();
        if(n==1) return 0;

        vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(n+1,vector<ll>(n+1,0)));
        vector<vector<ll>>prevMax(n+1,vector<ll>(n+1,0)),prevMaxSuff,colSum(n,vector<ll>(n+1,0));
        prevMaxSuff=prevMax;

        for(int c=0;c<n;c++){
            for(int r=1;r<=n;r++){
                colSum[c][r]=colSum[c][r-1]+grid[r-1][c];
            }
        }

        for(int i=1;i<n;i++){
            for(int currH=0;currH<=n;currH++){
                for(int prevH=0;prevH<=n;prevH++){
                    if(currH<=prevH){
                        ll extra=colSum[i][prevH]-colSum[i][currH];
                        dp[i][currH][prevH]=max(dp[i][currH][prevH],prevMaxSuff[prevH][0]+extra);
                    }
                    else {
                        ll extra=colSum[i-1][currH]-colSum[i-1][prevH];
                        dp[i][currH][prevH]=max({dp[i][currH][prevH],prevMaxSuff[prevH][currH],prevMax[prevH][currH]+extra});
                    }
                }
            }
        

            for(int currH=0;currH<=n;currH++){
                prevMax[currH][0]=dp[i][currH][0];
                for(int prevH=1;prevH<=n;prevH++){
                    ll penalty=(prevH>currH)?(colSum[i][prevH]-colSum[i][currH]):0;
                    prevMax[currH][prevH]=max(prevMax[currH][prevH-1],dp[i][currH][prevH]-penalty);
            }

                prevMaxSuff[currH][n]=dp[i][currH][n];
                for(int prevH=n-1;prevH>=0;prevH--){
                    prevMaxSuff[currH][prevH]=max(prevMaxSuff[currH][prevH+1],dp[i][currH][prevH]);
                }
            }
        }

        ll ans=0;
        for(int k=0;k<=n;k++){
            ans=max({ans,dp[n-1][n][k],dp[n-1][0][k]});
        }
        return ans;
    }
};

// Time Complexity : O(N^3);
// Space Complexity: O(N^3);