// Problem Link: https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/description/?envType=daily-question&envId=2026-03-19

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>diff(n+1,vector<int>(m+1,0)),hasX;
        hasX=diff;

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int currVal=0,currX=0;

                if(grid[i][j]=='X')currVal=1,currX=1;
                if(grid[i][j]=='Y')currVal=-1;

                diff[i+1][j+1]=currVal+diff[i+1][j]+diff[i][j+1]-diff[i][j];
                hasX[i+1][j+1]=currX | hasX[i+1][j] | hasX[i][j+1];

                if(diff[i+1][j+1]==0 && hasX[i+1][j+1])ans++;
            }
        }
        return ans;
    }
};

// Time Complexity : O(N*M) => O(N^2);
// Space Complexity: O(N*M) => O(N^2);