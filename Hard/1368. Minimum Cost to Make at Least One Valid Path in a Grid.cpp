// Problem Link: https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/?envType=daily-question&envId=2025-01-18

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        auto valid=[](int i,int j,auto &g){
        return i>=0 & j>=0 && i<g.size() && j<g[0].size();};
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>minCost(n,vector<int>(m,INT_MAX));
        deque<pair<int,int>>d;
        d.push_front({0,0});
        minCost[0][0]=0;

        while(d.size()){
            auto [r,c]=d.front();
            d.pop_front();
            
            int cnt=0;
            for(auto &cc:dir){
                int nr=r+cc.first,nc=c+cc.second;
                int cost=grid[r][c]!=cnt+++1?1:0;

                if(valid(nr,nc,grid) && minCost[r][c]+cost<minCost[nr][nc]){
                    minCost[nr][nc]=minCost[r][c]+cost;
                    if(cost)d.push_back({nr,nc});
                    else d.push_front({nr,nc});
                }
            }
        }
        return minCost[n-1][m-1];
    }
};

// Time Complexity : O(N*M) => O(N^2);
// Space Complexity: O(N*M) => O(N^2);