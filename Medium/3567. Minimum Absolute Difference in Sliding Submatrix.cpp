// Problem Link: https://leetcode.com/problems/minimum-absolute-difference-in-sliding-submatrix/?envType=daily-question&envId=2026-03-20

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>ans(m-k+1,vector<int>(n-k+1,0));

        for(int i=0;i<m-k+1;i++){
            for(int j=0;j<n-k+1;j++){
                vector<int>vals;
                for(int x=i;x<i+k;x++){
                    for(int y=j;y<j+k;y++)vals.push_back(grid[x][y]);
                }
                sort(vals.begin(),vals.end());

                int minDiff=INT_MAX;
                for(int id=0;id<vals.size()-1;id++){
                    if(vals[id+1]==vals[id])continue;
                    minDiff=min(minDiff,vals[id+1]-vals[id]);
                }

                if(minDiff!=INT_MAX)ans[i][j]=minDiff;
            }
        }
        return ans;
    }
};

// Time Complexity : O(M*N*(K^2)*logK) => O((N^4)logN);
// Space Complexity: O(M*N*(K^2)*logK) => O((N^4)logN);