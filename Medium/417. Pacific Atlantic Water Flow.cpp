// Problem Link: https://leetcode.com/problems/pacific-atlantic-water-flow/description/?envType=daily-question&envId=2025-10-05

class Solution {
public:
    vector<pair<int,int>>dir={{0,1},{1,0},{0,-1},{-1,0}};

    void dfs(int i,int j,auto &vis,auto &vc){
        int n=vc.size(),m=vc[0].size();
        vis[i][j]=1;
        for(auto &[x,y]:dir){
            int r=i+x,c=j+y;
            if(r<0 || r>=n || c<0 || c>=m || vis[r][c] || vc[i][j]>vc[r][c]) continue;
            dfs(r,c,vis,vc);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>>ans,p(n,vector<int>(m,0)),a=p;
        
        for(int i=0;i<n;i++){
            dfs(i,0,p,heights);
            dfs(i,m-1,a,heights);
        }
        for(int j=0;j<m;j++){
            dfs(0,j,p,heights);
            dfs(n-1,j,a,heights);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(p[i][j] && a[i][j])ans.push_back({i,j});
            }
        }
        return ans;
    }
};

// Time Complexity : O(N*M) => O(N^2);
// Space Complexity: O(N*M) => O(N^2);