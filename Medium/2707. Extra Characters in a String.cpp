// Problem Link: https://leetcode.com/problems/extra-characters-in-a-string/description/?envType=daily-question&envId=2024-09-23

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        set<string>st(dictionary.begin(),dictionary.end());
        int n=s.size();
        vector<int>dp(n+1,n);
        dp[0]=0;
        for(int i=1;i<n+1;i++){
            for(int j=0;j<i;j++){
                string sub=s.substr(j,i-j);
                if(st.find(sub)!=st.end())
                    dp[i]=min(dp[i],dp[j]);
            }
            dp[i]=min(dp[i],dp[i-1]+1);
        }
        return dp[n];
    }
};

// Time Complexity : O(N^3);
// Space Complexity: O(N);