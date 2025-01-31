// Problem Link: https://leetcode.com/problems/making-a-large-island/description/?envType=daily-question&envId=2025-01-31

class Solution {
public:
    map<int,int>mp;
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};

    int dfs(int i,int j,int label,auto &vc){
        int n=vc.size();
        if(i<0 || i>=n || j<0 || j>=n || vc[i][j]!=1) return 0;

        vc[i][j]=label;
        int size=1;
        for(auto &c:dir){
            size+=dfs(i+c[0],j+c[1],label,vc);
        }
        return mp[label]=size;
    }

    int connect(int i,int j,auto &vc){
        int n=vc.size();
        set<int>st;
        int total=1;
        for(auto &c:dir){
            int nr=i+c[0],nc=j+c[1];
            if(nr<0 || nr>=n || nc<0 || nc>=n || st.find(vc[nr][nc])!=st.end())continue;
            
            total+=mp[vc[nr][nc]];
            st.insert(vc[nr][nc]);
        }
        return total;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int label=2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(i,j,label,grid);
                    label++;
                }
            }
        }
        int ans=0;
        for(auto &c:mp)ans=max(ans,c.second);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    ans=max(ans,connect(i,j,grid));
                }
            }
        }
        return ans;
    }
};

// Time Complexity : O(N^2);
// Space Complexity: O(N^2);