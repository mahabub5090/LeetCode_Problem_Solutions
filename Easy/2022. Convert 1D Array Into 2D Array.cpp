// Problem Link: https://leetcode.com/problems/convert-1d-array-into-2d-array/description/?envType=daily-question&envId=2024-09-01

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(n*m != original.size())return {};

        int id=0;
        vector<vector<int>>vc(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vc[i][j]=original[id];
                id++;
            }
        }
        return vc;
    }
};

// Time Complexity : O(N)+O(N) => O(N);
// Space Complexity: O(N);