// Problem Link: https://leetcode.com/problems/flip-square-submatrix-vertically/description/?envType=daily-question&envId=2026-03-21

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int i=0;i<(k+1)/2;i++){
            for(int j=0;j<k;j++){
                swap(grid[x+i][y+j],grid[x+k-1-i][y+j]);
            }
        }
        return grid;
    }
};

// Time Complexity : O((K+1)/2*k) => O(K^2) => O(N^2);
// Space Complexity: O(1);