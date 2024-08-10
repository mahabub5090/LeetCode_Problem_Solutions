// Problem Link: https://leetcode.com/problems/regions-cut-by-slashes/description/?envType=daily-question&envId=2024-08-10

class Solution {
public:
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

    void dfs(int i,int j,auto &vc,auto &vis){
        if(i<0 || j<0 || i>=vc.size() || j>=vc[0].size() ||
            vis[i][j] || vc[i][j])return;

        vis[i][j]=1;

        for(int k=0;k<4;k++){
            dfs(i+dir[k][0],j+dir[k][1],vc,vis);
        }
    }

    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vc(n*3,vector<int>(m*3,0)),visit;
        visit=vc;  
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int i2=i*3,j2=j*3;
                char c=grid[i][j];
                if(c==' ')continue;
                vc[i2][j2+(c=='\\'?0:2)]=1;
                vc[i2+1][j2+1]=1;
                vc[i2+2][j2+(c=='\\'?2:0)]=1;  
            }
        }
        int ans=0;
        for(int i=0;i<n*3;i++){
            for(int j=0;j<m*3;j++){
                if(vc[i][j]==0 && visit[i][j]==0){
                    dfs(i,j,vc,visit);
                    ans++;
                }
            }
        }
        return ans;
    }
};

// Time Complexity : O(2*(3*r)*(3*c)) => O(N^2);
// Space Complexity: O(2*(3*r)*(3*c)) => O(N^2); 
// r=rows,c=columns;