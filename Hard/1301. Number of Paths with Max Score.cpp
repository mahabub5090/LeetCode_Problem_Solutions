// Problem Link: https://leetcode.com/problems/number-of-paths-with-max-score/description/?envType=daily-question&envId=2026-07-05

class Solution {
public:
    int mod=1e9+7;

    void update(auto &dp, int n,int x,int y,int u, int v){
        if(u>=n || v>=n || dp[u][v].first==-1) return;

        if(dp[u][v].first>dp[x][y].first) dp[x][y]=dp[u][v];
        else if(dp[u][v].first==dp[x][y].first){
            dp[x][y].second+=dp[u][v].second;
            dp[x][y].second%=mod;
        }
    }


    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();
        vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(n,{-1,0}));

        dp[n-1][n-1]={0,1};
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if((i!=n-1 || j!=n-1) && board[i][j]!='X'){
                    update(dp,n,i,j,i+1,j);
                    update(dp,n,i,j,i,j+1);
                    update(dp,n,i,j,i+1,j+1);

                    if(dp[i][j].first!=-1){
                        dp[i][j].first+=(board[i][j]=='E'?0:board[i][j]-'0');
                    }
                }
            }
        }

        if(dp[0][0].first==-1) return {{0,0}};
        return {dp[0][0].first,dp[0][0].second};
    }
};

// Time Complexity : O(N*N) => O(N^2);
// Space Complexity: O(N*N) => O(N^2);