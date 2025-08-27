// Problem Link: https://leetcode.com/problems/length-of-longest-v-shaped-diagonal-segment/description/?envType=daily-question&envId=2025-08-27

class Solution {
public:
    vector<vector<vector<vector<int>>>>memo;
    vector<vector<int>>dirs={{1,1},{1,-1},{-1,-1},{-1,1}};
    int dfs(int cx,int cy,int dir,int turn,int target,auto &grid){
        int n=grid.size(),m=grid[0].size();
        int nx=cx+dirs[dir][0];
        int ny=cy+dirs[dir][1];

        if(nx<0 || ny<0 || nx>=n || ny>=m || grid[nx][ny]!=target) return 0;

        int ans=memo[nx][ny][dir][turn];
        if(ans!=-1) return ans;

        int maxStep=dfs(nx,ny,dir,turn,2-target,grid);
        if(turn){
            maxStep=max(maxStep,dfs(nx,ny,(dir+1)%4,0,2-target,grid));
        }
        return memo[nx][ny][dir][turn]=maxStep+1;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        memo.assign(n,vector<vector<vector<int>>>(m,vector<vector<int>>(4,vector<int>(2,-1))));

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    for(int dir=0;dir<4;dir++){
                        ans=fmax(ans,dfs(i,j,dir,1,2,grid)+1);
                    }
                }
            }
        }
        return ans;
    }
};

// Time Complexity : O(N*M*4*2) => O(N^2);
// Space Complexity: O(N*M*4*2) => O(N^2);