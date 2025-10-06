// Problem Link: https://leetcode.com/problems/swim-in-rising-water/description/?envType=daily-question&envId=2025-10-06

class Solution {
public:
    vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};

    int dfs(int i,int j,int mid,auto &vis,auto &grid){
        int n=grid.size(),m=grid[0].size();
        if(i==n-1 && j==m-1)return 1;

        vis[i][j]=1;
        for(auto &[x,y]:dir){
            int r=i+x,c=j+y;
            if(r<0 || c<0 || r>=n || c>=m || vis[r][c])continue;
            if(grid[r][c]<=mid){
                if(dfs(r,c,mid,vis,grid))return 1;
            }
        }
        return 0;
    }
    int poss(int mid,auto &grid){
        int n=grid.size(),m=grid[0].size();
        if(grid[0][0]>mid)return 0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        return dfs(0,0,mid,vis,grid);
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int l=grid[0][0],r=0;
        for(auto &c:grid)for(auto &cc:c)r=max(r,cc);

        while(l<r){
            int mid=l+(r-l)/2;
            if(poss(mid,grid))r=mid;
            else l=mid+1;
        }
        return l;
    }
};

// Time Complexity : O(N*M) * O(log(M*N)) => O((N^2) * log(N^2));
// Space Complexity: O(N*M) => O(N^2);