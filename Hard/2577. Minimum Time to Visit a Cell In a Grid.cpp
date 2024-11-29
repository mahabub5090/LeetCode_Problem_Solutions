// Problem Link: https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/description/?envType=daily-question&envId=2024-11-29

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if(grid[0][1]>1 && grid[1][0]>1)return -1;
        int n=grid.size(),m=grid[0].size();
        vector<pair<int,int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>>pq;
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        pq.push({0,0,0});

        while(pq.size()){
            auto [time,row,col]=pq.top();
            pq.pop();
            if(row==n-1 && col==m-1)return time;
            if(vis[row][col])continue;
            vis[row][col]=1;

            for(auto [x,y]:dir){
                int nextRow=row+x,nextCol=col+y;
                if(nextRow<0 || nextRow>=n || nextCol<0 || nextCol>=m || vis[nextRow][nextCol])continue;
    
                int extra=((grid[nextRow][nextCol]-time)%2)?0:1;
                int nextTime=max(grid[nextRow][nextCol]+extra,time+1);
                pq.push({nextTime,nextRow,nextCol});
            }
        }
        return 0;
    }
};

// Time Complexity : O(N*M*log(N*M)) => O((N^2)*log(N^2));
// Space Complexity: O(N*M) => O(N^2);