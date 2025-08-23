// Problem Link: https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-ii/description/?envType=daily-question&envId=2025-08-23

class Solution {
public:
    auto rotate(auto &grid){
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>rotateGrid(m,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                rotateGrid[m-j-1][i]=grid[i][j];
            }
        }
        return rotateGrid;
    }
    int miniSum(auto &grid,int u,int d,int l,int r){
        int mini=grid.size(),maxi=0;
        int minj=grid[0].size(),maxj=0;
        for(int i=u;i<=d;i++){
            for(int j=l;j<=r;j++){
                if(grid[i][j]){
                    mini=min(mini,i);
                    maxi=max(maxi,i);
                    minj=min(minj,j);
                    maxj=max(maxj,j);
                }
            }
        }
        return mini<=maxi?((maxi-mini+1)*(maxj-minj+1)):INT_MAX/3;
    }
    int solve(auto &grid){
        int n=grid.size(),m=grid[0].size();
        int ans=n*m;

        for(int i=0;i+1<n;i++){
            for(int j=0;j+1<m;j++){
                ans=min(ans,miniSum(grid,0,i,0,m-1)+miniSum(grid,i+1,n-1,0,j)+miniSum(grid,i+1,n-1,j+1,m-1));
                ans=min(ans,miniSum(grid,0,i,0,j)+miniSum(grid,0,i,j+1,m-1)+miniSum(grid,i+1,n-1,0,m-1));
            }
        }

        for(int i=0;i+2<n;i++){
            for(int j=i+1;j+1<n;j++){
                ans=min(ans,miniSum(grid,0,i,0,m-1)+miniSum(grid,i+1,j,0,m-1)+miniSum(grid,j+1,n-1,0,m-1));
            }
        }
        return ans;
    }

    int minimumSum(vector<vector<int>>& grid) {
        vector<vector<int>>rotateGrid=rotate(grid);
        return min(solve(grid),solve(rotateGrid));
    }
};

// Time Complexity : O((N^2)*(M^2)) => O(N^4);
// Space Complexity: O(N*M) => O(N^2);