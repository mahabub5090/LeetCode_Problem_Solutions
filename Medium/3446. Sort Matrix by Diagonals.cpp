// Problem Link: https://leetcode.com/problems/sort-matrix-by-diagonals/description/

class Solution {
    public:
        vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
            int n=grid.size();
            for(int i=0;i<n;i++){
                vector<int>vc;
                int j=i,k=0;
                while(j<n && k<n){
                    vc.push_back(grid[j][k]);
                    j++,k++;
                }
                sort(vc.begin(),vc.end());
                j=i,k=0;
                while(j<n && k<n){
                    grid[j][k]=vc.back();
                    vc.pop_back();
                    j++,k++;
                }
    
                if(i==0)continue;
    
                vc.clear();
                j=0,k=i;
                while(j<n && k<n){
                    vc.push_back(grid[j][k]);
                    j++,k++;
                }
                sort(vc.rbegin(),vc.rend());
                j=0,k=i;
                while(j<n && k<n){
                    grid[j][k]=vc.back();
                    vc.pop_back();
                    j++,k++;
                }
                
            }
            return grid;
        }
    };
    
    // Time Complexity : O(N*N) => O(N^2);
    // Space Complexity: O(N*N) => O(N^2);