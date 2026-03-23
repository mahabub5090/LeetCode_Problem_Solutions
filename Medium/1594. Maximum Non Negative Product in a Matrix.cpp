// Problem Link: https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/description/?envType=daily-question&envId=2026-03-23

class Solution {
public:
    using ll = long long;

    int maxProductPath(vector<vector<int>>& grid) {
        int mod=1e9+7;
        int m=grid.size(),n=grid[0].size();
        vector<vector<ll>>maxp(m,vector<ll>(n)),minp;
        minp=maxp;

        maxp[0][0]=minp[0][0]=grid[0][0];
        for(int i=1;i<n;i++){
            maxp[0][i]=minp[0][i]=maxp[0][i-1]*grid[0][i];
        }
        for(int i=1;i<m;i++){
            maxp[i][0]=minp[i][0]=maxp[i-1][0]*grid[i][0];
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(grid[i][j]>=0){
                    maxp[i][j]=max(maxp[i][j-1],maxp[i-1][j])*grid[i][j];
                    minp[i][j]=min(minp[i][j-1],minp[i-1][j])*grid[i][j];
                }
                else{
                    maxp[i][j]=min(minp[i][j-1],minp[i-1][j])*grid[i][j];
                    minp[i][j]=max(maxp[i][j-1],maxp[i-1][j])*grid[i][j];
                }
            }
        }

        if(maxp[m-1][n-1]<0)return -1;
        return maxp[m-1][n-1]%mod;
    }
};

// Time Complexity : O(M*N) => O(N^2);
// Space Complexity: O(M*N) => O(N^2);