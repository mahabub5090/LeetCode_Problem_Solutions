// Problem Link: https://leetcode.com/problems/minimum-cost-path-with-teleportations/description/?envType=daily-question&envId=2026-01-28

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        vector<pair<int,int>>points;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                points.push_back({i,j});
            }
        }

        sort(points.begin(),points.end(),[&](auto &c,auto &d){
            return grid[c.first][c.second]<grid[d.first][d.second];
        });
        
        vector<vector<int>>costs(n,vector<int>(m,INT_MAX));

        for(int t=0;t<=k;t++){
            int minCost=INT_MAX;

            for(int i=0,j=0;i<points.size();i++){
                minCost=min(minCost,costs[points[i].first][points[i].second]);
                
                if(i+1<n*m){
                    auto [p,ps]=points[i];
                    auto [p2,ps2]=points[i+1];
                    if(grid[p][ps]==grid[p2][ps2])continue;
                }

                for(int l=j;l<=i;l++)costs[points[l].first][points[l].second]=minCost;

                j=i+1;       
            }

            for(int i=n-1;i>=0;i--){
                for(int j=m-1;j>=0;j--){
                    if(i==n-1 && j==m-1){
                        costs[i][j]=0;
                        continue;
                    }
                    if(i!=n-1)costs[i][j]=min(costs[i][j],costs[i+1][j]+grid[i+1][j]);
                    if(j!=m-1)costs[i][j]=min(costs[i][j],costs[i][j+1]+grid[i][j+1]);
                }
            }
        }
        return costs[0][0];
    }
};

// Time Complexity : O(N*M) + O(N*M*log(M*N)) + O(K*(2*N*M)) => O(N^3);
// Space Complexity: O(2*(N*M)) => O(N^2);