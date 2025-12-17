// Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v/description/?envType=daily-question&envId=2025-12-17

class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n=prices.size();
        vector<vector<long long>>dp(k+1,vector<long long>(3));

        for(int j=1;j<=k;j++){
            dp[j][1]=-prices[0];
            dp[j][2]=prices[0];
        }

        for(int i=1;i<n;i++){
            for(int j=k;j>0;j--){
                long long mx=max(dp[j][1]+prices[i],dp[j][2]-prices[i]);
                dp[j][0]=max(dp[j][0],mx);
                dp[j][1]=max(dp[j][1],dp[j-1][0]-prices[i]);
                dp[j][2]=max(dp[j][2],dp[j-1][0]+prices[i]);
            }
        }

        return dp[k][0];
    }
};

// Time Complexity : O(N*K) => O(N^2);
// Space Complexity: O(3*K) => O(N);