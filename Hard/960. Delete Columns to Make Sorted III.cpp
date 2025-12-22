// Problem Link: https://leetcode.com/problems/delete-columns-to-make-sorted-iii/description/?envType=daily-question&envId=2025-12-22

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size(),m=strs[0].size();
        vector<int>dp(m,1);

        for(int i=m-2;i>=0;i--){
            for(int j=i+1;j<m;j++){
                int f=1;
                for(int k=0;k<n;k++){
                    if(strs[k][i]>strs[k][j]){
                        f=0;
                        break;
                    }
                }
                if(f)dp[i]=max(dp[i],dp[j]+1);
            }
        }

        int keep=0;
        for(auto &c:dp)keep=max(keep,c);
        return m-keep;
    }
};

// Time Complexity : O(M*M*N) => O(N^3);
// Space Complexity: O(N);
// Here M is strs[0].size();