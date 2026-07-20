// Problem Link: https://leetcode.com/problems/shift-2d-grid/description/?envType=daily-question&envId=2026-07-20

class Solution {
public:
    void gridReverse(int start,int end, auto &grid){
        int m=grid.size(), n=grid[0].size();

        while(start<end){
            int si=start/n, sj=start%n;
            int ei=end/n, ej=end%n;

            swap(grid[si][sj],grid[ei][ej]);
            start++;
            end--;
        }
    }

    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(), n=grid[0].size(), len=m*n;
        k%=len;

        gridReverse(0,len-1,grid);
        gridReverse(0,k-1,grid);
        gridReverse(k,len-1,grid);
        return grid;      
    }
};

// Time Complexity : O(M*N) + O(K) + O(M*N-k) => O(2*M*N) => O(M*N);
// Space Complexity: O(1);