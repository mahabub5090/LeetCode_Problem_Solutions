// Problem Link: https://leetcode.com/problems/trapping-rain-water-ii/description/?envType=daily-question&envId=2025-01-19

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n=heightMap.size(),m=heightMap[0].size();
        vector<vector<int>>dir={{0,-1},{0,1},{-1,0},{1,0}};

        vector<vector<int>>vis(n,vector<int>(m,0));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;

         for(int i=0;i<n;i++) {
            for(int j:{0,m-1}) {
                pq.push({heightMap[i][j],i,j});
                vis[i][j]=1;
            }
        }
        for(int j=1;j<m-1;j++) {
            for(int i:{0,n-1}) {
                pq.push({heightMap[i][j],i,j});
                vis[i][j]=1;
            }
        }
        
        int ans=0;
        while(pq.size()){
            auto cell=pq.top();
            pq.pop();
            int height=cell[0],x=cell[1],y=cell[2];

            for(auto &d:dir){
                int nx=x+d[0],ny=y+d[1];
                if (nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny]){
                    ans+=max(0,height-heightMap[nx][ny]);
                    pq.push({max(height,heightMap[nx][ny]),nx,ny});
                    vis[nx][ny]=1;
                }
            }
        }
        return ans;
    }
};

// Time Complexity : O(N*M*log(N+M)) => O((N^2)*logN);
// Space Complexity: O(N*M) => O(N^2);