// Problem Link: https://leetcode.com/problems/special-positions-in-a-binary-matrix/description/?envType=daily-question&envId=2026-03-04

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<int>row(m,0),col(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j])row[i]++,col[j]++;
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] && row[i]==1 && col[j]==1)ans++;
            }
        }
        return ans;
    }
};

// Time Complexity : O(M*N) => O(N^2);
// Space Complexity: O(M) + O(N) => O(N);