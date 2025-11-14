// Problem Link: https://leetcode.com/problems/increment-submatrices-by-one/description/?envType=daily-question&envId=2025-11-14

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>vc(n,vector<int>(n));
        for(auto &c:queries){
            for(int i=c[0];i<=c[2];i++){
                for(int j=c[1];j<=c[3];j++){
                    vc[i][j]++;
                }
            }
        }
        return vc;
    }
};

// Time Complexity : O(Q*N*N) => O(N^3);
// Space Complexity: O(N^2);