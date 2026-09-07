// Problem Link: https://leetcode.com/problems/distinct-subsequences-ii/description/?envType=daily-question&envId=2026-09-07

class Solution {
public:
    int distinctSubseqII(string s) {
        int n=s.size(), mod=1e9+7;
        vector<long long> dp(n+1,0);
        dp[0]=1;
        unordered_map<char,int> mp;

        for(int i=0;i<n;i++){
            dp[i+1]=(2*dp[i])%mod;

            if(mp.count(s[i])){
                int prevIndex=mp[s[i]];
                dp[i+1]-=dp[prevIndex];
                dp[i+1]%=mod;
            }

            mp[s[i]]=i;
        }
        return (dp[n]-1+mod)%mod;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N) + O(26) => O(N);