// Problem Link: https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-ii/description/?envType=daily-question&envId=2025-05-16

class Solution {
public:
    int dist(string &a,string &b){
        if(a.size()!=b.size())return 0;
        int cnt=0;
        for(int i=0;i<a.size();i++)cnt+=a[i]!=b[i];
        return cnt==1;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=groups.size();
        vector<int>dp(n,1),prev(n,-1);
        int maxi=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(dist(words[j],words[i])==1 && groups[j]!=groups[i] && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    prev[i]=j;
                }
                if(dp[i]>dp[maxi])maxi=i;
            }
        }
        vector<string>ans;
        for(int i=maxi;i>=0;i=prev[i]){
            ans.push_back(words[i]);
        }   
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// Time Complexity : O(N^2);
// Space Complexity: O(N);