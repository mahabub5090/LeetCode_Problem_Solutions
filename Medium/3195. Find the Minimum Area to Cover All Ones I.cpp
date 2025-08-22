// Problem Link: https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/description/?envType=daily-question&envId=2025-08-22

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int mini=n,maxi=0,minj=m,maxj=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    mini=min(mini,i);
                    maxi=max(maxi,i);
                    minj=min(minj,j);
                    maxj=max(maxj,j);
                }
            }
        }
        return (maxi-mini+1)*(maxj-minj+1);
    }
};

// Time Complexity : O(N*M) => O(N^2);
// Space Complexity: O(1);