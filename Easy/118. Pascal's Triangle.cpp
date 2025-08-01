// Problem Link: https://leetcode.com/problems/pascals-triangle/description/?envType=daily-question&envId=2025-08-01

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>pascalTriangle={{1}};

        for(int i=1;i<numRows;i++){
            vector<int>row(i+1,1);
            for(int j=1;j<i;j++){
                row[j]=pascalTriangle[i-1][j-1]+pascalTriangle[i-1][j];
            }
            pascalTriangle.push_back(row);
        }
        return pascalTriangle;
    }
};

// Time Complexity : O(N^2);
// Space Complexity: O(N^2);