// Problem Link: https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/description/?envType=daily-question&envId=2024-11-28

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        queue<pair<int,int>>q;
        dist[0][0]=0;
        q.push({0,0});
        vector<pair<int,int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
        while(q.size()){
            auto c=q.front();
            q.pop();
            for(auto &[x,y]:dir){
                int nx=c.first+x,ny=c.second+y;
                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    int newDist=dist[c.first][c.second]+grid[nx][ny];
                    if(newDist<dist[nx][ny]){
                        dist[nx][ny]=newDist;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};

// Time Complexity : O(N*M) => O(N^2);
// Space Complexity: O(N*M) => O(N^2);