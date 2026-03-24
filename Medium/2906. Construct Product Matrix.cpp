// Problem Link: https://leetcode.com/problems/construct-product-matrix/description/?envType=daily-question&envId=2026-03-24

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),mod=12345;
        vector<vector<int>>ans(n,vector<int>(m));

        long long suff=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                ans[i][j]=suff;
                
                suff*=grid[i][j];
                suff%=mod;
            }
        }

        long long pref=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]*=pref;
                ans[i][j]%=mod;

                pref*=grid[i][j];
                pref%=mod;
            }
        }
        return ans;
    }
};

// Time Complexity : O(N*M) + O(N*M) => O(N^2);
// Space Complexity: O(N*M) => O(N^2);