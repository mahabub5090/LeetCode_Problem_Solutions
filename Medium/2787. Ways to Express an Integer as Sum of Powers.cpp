// Problem Link: https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/description/?envType=daily-question&envId=2025-08-12

class Solution {
public:
    int numberOfWays(int n, int x) {
        int mod=1e9+7;
        vector<int>dp(n+1);
        dp[0]=1;

        for(int i=1;i<=n;i++){
            int val=pow(i,x);
            if(val>n)break;
            for(int j=n;j>=val;j--){
                dp[j]+=dp[j-val];
                dp[j]%=mod;
            }
        }

        return dp[n];
    }
};

// Time Complexity : O(N * N^(1/X)) => O(N^2);
// Space Complexity: O(N);