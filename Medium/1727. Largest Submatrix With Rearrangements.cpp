// Problem Link: https://leetcode.com/problems/largest-submatrix-with-rearrangements/?envType=daily-question&envId=2026-03-17

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int ans=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]!=0 && i>0)matrix[i][j]+=matrix[i-1][j];
            }
            vector<int>currRow=matrix[i];
            sort(currRow.rbegin(),currRow.rend());

            for(int i=0;i<n;i++){
                ans=max(ans,currRow[i]*(i+1));
            }
        }
        return ans;
    }
};

// Time Complexity : O(M*N*logN) => O((N^2)logN);
// Space Complexity: O(M*N) => O(N^2);