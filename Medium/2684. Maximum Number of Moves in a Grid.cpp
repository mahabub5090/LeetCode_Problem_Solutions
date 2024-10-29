// Problem Link: https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/submissions/1437413028/?envType=daily-question&envId=2024-10-29

class Solution {
public:
    int ans;
    int solve(int i,int j,auto &vc,auto &mem){
       if(mem[i][j]!=-1)return mem[i][j];
       int cnt=0,n=vc.size(),m=vc[0].size();
       if(i-1>=0 && j+1<m && vc[i-1][j+1]>vc[i][j])
            cnt=1+solve(i-1,j+1,vc,mem);
       if(j+1<m && vc[i][j+1]>vc[i][j])
            cnt=max(cnt,1+solve(i,j+1,vc,mem));
       if(i+1<n && j+1<m && vc[i+1][j+1]>vc[i][j])
            cnt=max(cnt,1+solve(i+1,j+1,vc,mem));
       return mem[i][j]=cnt;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>mem(n,vector<int>(m,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,solve(i,0,grid,mem));
        }
        return ans;
    }
};

// Time Complexity : O(3*N*M) => O(N*M) => O(N^2);
// Space Conplexity: O(N*M) => O(N^2);