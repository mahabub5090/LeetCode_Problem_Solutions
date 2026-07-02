// Problem Link: https://leetcode.com/problems/find-a-safe-walk-through-a-grid/?envType=daily-question&envId=2026-07-02

class Solution {
public:
    vector<pair<int,int>> dir={{0,1},{1,0},{-1,0},{0,-1}};

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dis(m,vector<int>(n,-1));

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({grid[0][0],0,0});

        while(pq.size()){
            auto [val,x,y]=pq.top();
            pq.pop();

            if(dis[x][y]>=0) continue;
            dis[x][y]=val;

            for(auto &[i,j]:dir){
                int nx=x+i, ny=y+j;

                if(nx<0 || nx>=m || ny<0 || ny>=n || dis[nx][ny]>=0) continue;

                pq.push({val+grid[nx][ny],nx,ny});
            }
        }
        return health>dis[m-1][n-1];
    }
};

// Time Complexity : O((M*N)log(M*N));
// Space Complexity: O(M*N) + O(M*N) => O(M*N);