// Problem Link: https://leetcode.com/problems/count-sub-islands/description/?envType=daily-question&envId=2024-08-28

class Solution {
public:
    int cnt=0,cnt2=0,cnt3=0;
    bool dfs(int i,int j,auto &vis,auto &a,auto &b){
        if(i<0 || j<0 || i>=b.size() || j>=b[0].size() || vis[i][j] || b[i][j]==0)return cnt2==cnt3;
        vis[i][j]=1;
        cnt2++;
        if(a[i][j]==1)cnt3++;
        dfs(i+1,j,vis,a,b);
        dfs(i,j+1,vis,a,b);
        dfs(i-1,j,vis,a,b);
        dfs(i,j-1,vis,a,b);
        return cnt2==cnt3;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vector<vector<int>>vis(grid2.size(),vector<int>(grid2[0].size(),0));
        for(int i=0;i<grid2.size();i++){
            for(int j=0;j<grid2[0].size();j++){
                if(grid2[i][j] && vis[i][j]==0){
                    cnt2=0,cnt3=0;
                    if(dfs(i,j,vis,grid1,grid2))cnt++;
                };
            }
        }
        return cnt;
    }
};

// Time Complexity : O(n*m) => O(N^2);
// space Complexity: O(n*m) => O(N^2);
// n= rows, m= columns;