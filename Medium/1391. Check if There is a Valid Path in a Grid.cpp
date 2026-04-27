// Problem Link: https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/description/?envType=daily-question&envId=2026-04-27

class Solution {
public:
    unordered_map<int,vector<pair<int,int>>>mp;
    
    int dfs(int i,int j,auto &vc,auto &vis){
        int m=vc.size(),n=vc[0].size();
        if(i==m-1 && j==n-1) return 1;

        vis[i][j]=1;
        for(auto &[x,y]:mp[vc[i][j]]){
            int ni=i+x,nj=j+y;
            if(ni<0 || nj<0 || ni==m || nj==n || vis[ni][nj]) continue;

            int flag=0;
            for(auto &[x2,y2]:mp[vc[ni][nj]]){
                if(i==ni+x2 && j==nj+y2){
                    flag=1;
                    break;
                };
            }
            if(flag && dfs(ni,nj,vc,vis)) return 1;
        }
        return 0;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        mp[1]={{0,1},{0,-1}};
        mp[2]={{1,0},{-1,0}};
        mp[3]={{1,0},{0,-1}};
        mp[4]={{0,1},{1,0}};
        mp[5]={{-1,0},{0,-1}};
        mp[6]={{-1,0},{0,1}};
        vector<vector<int>>vis(m,vector<int>(n,0));
        return dfs(0,0,grid,vis);
    }
};

// Time Complexity : O(M*N) => O(N^2);
// Space Complexity: O(M*N) => O(N^2);