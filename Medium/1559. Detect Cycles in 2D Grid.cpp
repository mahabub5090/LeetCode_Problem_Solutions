// Problem Link: https://leetcode.com/problems/detect-cycles-in-2d-grid/description/?envType=daily-question&envId=2026-04-26

class Solution {
public:
    vector<int> x={1,-1,0,0};
    vector<int> y={0,0,-1,1};

    int dfs(int i,int j,int pi,int pj,auto &vc,auto &vis){
        int m=vc.size(),n=vc[0].size();
        vis[i][j]=1;

        for(int d=0;d<4;d++){
            int ni=i+x[d],nj=j+y[d];
            if(ni<0 || nj<0 || ni==m || nj==n || vc[ni][nj]!=vc[i][j])continue;
            
            if(vis[ni][nj] && (ni!=pi || nj!=pj)) return 1;
            if(!vis[ni][nj] && dfs(ni,nj,i,j,vc,vis)) return 1;

        }
        return 0;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j])continue;
                if(dfs(i,j,-1,-1,grid,vis)) return 1;
            }
        }
        return 0;
    }
};

// Time Complexity : O(M*N) => O(N^2);
// Space Complexity: O(M*N) => O(N^2);