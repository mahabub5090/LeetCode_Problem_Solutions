// Problem Link: https://leetcode.com/problems/equal-sum-grid-partition-ii/description/?envType=daily-question&envId=2026-03-26

class Solution {
public:
    using ll = long long;

    vector<vector<int>> rotation(auto &grid){
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[j][m-1-i]=grid[i][j];
            }
        }
        return ans;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        ll tt=0,sum=0,tag=0;

        unordered_set<ll>have;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)tt+=grid[i][j];
        }

        for(int k=0;k<4;k++){
            have.clear(),have.insert(0);
            m=grid.size(),n=grid[0].size();
            sum=0;

            if(m<2){
                grid=rotation(grid);
                continue;
            }

            if(n==1){
                for(int i=0;i<m-1;i++){
                    sum+=grid[i][0];
                    tag=2*sum-tt;
                    if(tag==0 || tag==grid[0][0] || tag==grid[i][0])return 1;
                }
                grid=rotation(grid);
                continue;
            }

            for(int i=0;i<m-1;i++){
                for(int j=0;j<n;j++){
                    have.insert(grid[i][j]);
                    sum+=grid[i][j];
                }
                tag=2*sum-tt;
                if(i==0){
                    if(tag==0 || tag==grid[0][0] || tag==grid[0][n-1])return 1;
                    continue;
                }
                if(have.count(tag))return 1;
            }

            grid=rotation(grid);
        }
        return 0;
    }
};

// Time Complexity : O(M*N) + O(4*(M*N+M+M*N)) => O(N^2);
// Space Complexity: O(M*N) + O(4*M*N) => O(N^2);