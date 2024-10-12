// Problem Link: https://leetcode.com/problems/maximum-energy-boost-from-two-drinks/description/

class Solution {
public:
    long long maxEnergyBoost(vector<int>& a, vector<int>& b) {
        int n=a.size();
        vector<pair<long long,long long>>dp(n+1,{0,0});
        for(int i=1;i<n+1;i++){
            dp[i].first=max(dp[i-1].second,dp[i-1].first+a[i-1]);
            dp[i].second=max(dp[i-1].first,dp[i-1].second+b[i-1]);
            dp[i].first=max(dp[i].first,dp[i-1].second);
            dp[i].second=max(dp[i].second,dp[i-1].first);
        }
        return max(dp[n].first,dp[n].second);
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);

