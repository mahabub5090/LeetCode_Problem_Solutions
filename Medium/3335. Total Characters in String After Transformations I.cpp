// Problem Link: https://leetcode.com/problems/total-characters-in-string-after-transformations-i/description/?envType=daily-question&envId=2025-05-13

class Solution {
public:
    int mod=1e9+7;
    vector<vector<long long>>dp;

    long long contribute(char c,int t){
        if(t==0)return 1;
        if(dp[c-'a'][t]!=-1)return dp[c-'a'][t];

        if(c=='z'){
            long long first=contribute('a',t-1);
            long long second=contribute('b',t-1);
            return dp[c-'a'][t]=(first+second)%mod;
        }
        return dp[c-'a'][t]=contribute(c+1,t-1);
    }
    int lengthAfterTransformations(string s, int t) {
        long long ans=0;
        dp.assign(27,vector<long long>(t+100,-1));
        for(auto &c:s)ans+=contribute(c,t),ans%=mod;
        return ans;
    }
};

// Time Complexity : O(s.size()+t) => O(N);
// Space Complexity: O(t) => O(N);