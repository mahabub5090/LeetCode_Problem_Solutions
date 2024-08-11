// Problem Link: https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/submissions/1352287340/?envType=daily-question&envId=2024-08-11

class Solution {
public:
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

    void dfs(int i,int j,auto &vc,auto &vis){
        if(i<0 || j<0 || i>=vc.size() || j>=vc[0].size() ||
            vc[i][j]==0 || vis[i][j]) return;
        vis[i][j]=1;
        for(auto &[a,b]:dir) dfs(i+a,j+b,vc,vis);
    }

    int count_island(auto &vc,auto &vis){
        int cnt=0,n=vc.size(),m=vc[0].size();
        vis.assign(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vc[i][j]&&vis[i][j]==0){
                    dfs(i,j,vc,vis);
                    cnt++;
                    if(cnt==2)break;
                }
            }
        }
        return cnt;
    }

    int minDays(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        if(count_island(grid,vis)!=1) return 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    grid[i][j]=0;
                    if(count_island(grid,vis)!=1) return 1;
                    grid[i][j]=1;
                }
            }
        }
        return 2;
    }
};

// Time Complexity : O(r*c)+O(r*c)^2 => O(N^4);
// Space Complexity: O(2*r*c) => O(N^2);
// r=rows,c=colums; 