// Problem Link: https://leetcode.com/problems/stone-game-viii/description/?envType=daily-question&envId=2026-08-24

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        vector<int> pref(n);
        pref[0]=stones[0];
        for(int i=1;i<n;i++) pref[i]=pref[i-1]+stones[i];

        vector<int> dp(n);
        dp[n-1]=pref[n-1];
        for(int i=n-2;i>=1;i--){
            dp[i]=max(dp[i+1],pref[i]-dp[i+1]);
        }
        return dp[1];
    }
};

// Time Complexity : O(N) + O(N) => O(N);
// Space Complexity: O(N) + O(N) => O(N);