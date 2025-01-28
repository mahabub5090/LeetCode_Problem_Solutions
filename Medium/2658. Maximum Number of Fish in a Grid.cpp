// Problem Link: https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/?envType=daily-question&envId=2025-01-28

class Solution {
public:
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    int dfs(int i,int j,auto &vis,auto &vc){
        if(i<0 || j<0 || i>=vc.size() || j>=vc[0].size() || vis[i][j]++ || !vc[i][j])return 0;
        int tt=vc[i][j];
        for(auto &c:dir){
            tt+=dfs(i+c[0],j+c[1],vis,vc);
        }
        return tt;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j])ans=max(ans,dfs(i,j,vis,grid));
            }
        }
        return ans;
    }
};

// Time Complexity : O(N*M) => O(N^2);
// Space Complexity: O(N*M) => O(N^2);