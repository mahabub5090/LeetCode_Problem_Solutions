// Problem Link: https://leetcode.com/problems/stone-game-iv/description/?envType=daily-question&envId=2026-08-10

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1);

        for(int i=0;i<=n;i++){
            if(dp[i]) continue;

            for(int j=1;i+(j*j)<=n;j++) dp[i+(j*j)]++; 
        }
        return dp[n];
    }
};

// Time Complexity : O(N*sqrt(N));
// Space Complexity: O(N);