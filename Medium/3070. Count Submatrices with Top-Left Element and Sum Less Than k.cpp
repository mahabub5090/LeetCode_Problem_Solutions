// Problem Link: https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/?envType=daily-question&envId=2026-03-18

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        vector<int>cols(m,0);

        int ans=0;
        for(int i=0;i<n;i++){
            int rows=0;
            for(int j=0;j<m;j++){
                cols[j]+=grid[i][j];
                rows+=cols[j];
                if(rows<=k)ans++;
            }
        }
        return ans;
    }
};

// Time Complexity : O(N*M) => O(N^2);
// Space Complexity: O(N*M) => O(N^2);