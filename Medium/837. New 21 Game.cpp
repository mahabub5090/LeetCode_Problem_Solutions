// Problem Link: https://leetcode.com/problems/new-21-game/description/?envType=daily-question&envId=2025-08-17

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double>dp(n+1);
        dp[0]=1;
        double s=k?1:0;

        for(int i=1;i<=n;i++){
            dp[i]=s/maxPts;
            if(i<k)s+=dp[i];
            if(i-maxPts>=0 && i-maxPts<k)s-=dp[i-maxPts];
        }
        return accumulate(dp.begin()+k,dp.end(),0.0);
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);