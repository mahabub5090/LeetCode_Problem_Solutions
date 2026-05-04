// Problem Link: https://leetcode.com/problems/rotate-image/description/?envType=daily-question&envId=2026-05-04

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++) reverse(matrix[i].begin(),matrix[i].end());
    }
};

// Time Complexity : O(N*N) + O(N*N) => O(N^2);
// Space Complexity: O(1);