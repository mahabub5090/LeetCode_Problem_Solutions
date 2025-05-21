// Problem Link: https://leetcode.com/problems/set-matrix-zeroes/description/?envType=daily-question&envId=2025-05-21

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        unordered_set<int>r,c;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!matrix[i][j]){
                    if(!r.count(i))r.insert(i);
                    if(!c.count(j))c.insert(j);
                };
            }
        }
        for(auto &i:r){
            for(int j=0;j<m;j++)matrix[i][j]=0;
        }
        for(auto &j:c){
            for(int i=0;i<n;i++)matrix[i][j]=0;
        }
    }
};

// Time Complexity : O(N*M) => O(N^2);
// Space Complexity: O(N+M) => O(N);