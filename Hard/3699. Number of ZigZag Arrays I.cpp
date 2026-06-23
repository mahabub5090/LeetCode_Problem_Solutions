// Problem Link: https://leetcode.com/problems/number-of-zigzag-arrays-i/description/?envType=daily-question&envId=2026-06-23

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int m=r-l+1, mod=1e9+7;
        vector<int> dp(m,0), dp2(m,0), sum(m+1,0),sum2(m+1,0);

        for(int i=0;i<m;i++) dp[i]=dp2[i]=1;

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                sum[j+1]=(sum[j]+dp[j])%mod;
                sum2[j+1]=(sum2[j]+dp2[j])%mod;
            }

            for(int j=0;j<m;j++){
                dp[j]=(sum2[m]-sum2[j+1]+mod)%mod;
                dp2[j]=sum[j];
            }
        }
        
        int ans=0;
        for(int j=0;j<m;j++){
            ans=(ans+dp[j])%mod;
            ans=(ans+dp2[j])%mod;
        }
        return ans;
    }
};

// Time Complexity : O(M) + O(N*(M+M)) + O(M) => O(N*M);
// Space Complexity: O(M) + O(M) + O(M+1) + O(M+1) => O(M);
// M = r-l+1;