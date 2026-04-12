// Problem Link: https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/description/?envType=daily-question&envId=2026-04-12

class Solution {
public:
    int getDist(int p,int q){
        int x=p/6,y=p%6;
        int x2=q/6,y2=q%6;
        return abs(x-x2)+abs(y-y2);
    }

    int minimumDistance(string word) {
        int n=word.size();
        int dp[n][26][26];

        for(int i=0;i<n;i++){
            for(int j=0;j<26;j++){
                fill(dp[i][j],dp[i][j]+26,INT_MAX/2);
            }
        }
        for(int i=0;i<26;i++){
            dp[0][i][word[0]-'A']=dp[0][word[0]-'A'][i]=0;
        }

        for(int i=1;i<n;i++){
            int prev=word[i-1]-'A';
            int curr=word[i]-'A';
            int dist=getDist(prev,curr);

            for(int j=0;j<26;j++){
                dp[i][curr][j]=min(dp[i][curr][j],dp[i-1][prev][j]+dist);
                dp[i][j][curr]=min(dp[i][j][curr],dp[i-1][j][prev]+dist);
                if(prev==j){
                    for(int k=0;k<26;k++){
                        int dist2=getDist(k,curr);
                        dp[i][curr][j]=min(dp[i][curr][j],dp[i-1][k][j]+dist2);
                        dp[i][j][curr]=min(dp[i][j][curr],dp[i-1][j][k]+dist2);
                    }
                }
            }
        }

        int ans=INT_MAX;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                ans=min(ans,dp[n-1][i][j]);
            }
        }
        return ans;
    }
};

// Time Complexity : O(N*26) + O(N*(26+26)) + O(N*26) => O(N);
// Space Complexity: O(N*26*26) => O(N);