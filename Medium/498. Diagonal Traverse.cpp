// Problem Link: https://leetcode.com/problems/diagonal-traverse/submissions/1747993889/?envType=daily-question&envId=2025-08-25

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<int>ans;
        vector<int>diagonals;
        for(int d=0;d<n+m-1;d++){
            int r=d<m?0:d-m+1;
            int c=d<m?d:m-1;
            while(r<n && c>-1){
                diagonals.push_back(mat[r][c]);
                r++,c--;
            }
            if(d%2==0)reverse(diagonals.begin(),diagonals.end());
            for(auto &c:diagonals)ans.push_back(c);
            diagonals.clear();
        }
        return ans;
    }
};

// Time Complexity : O(N*M) => O(N^2);
// Space Complexity: O(N*M) => O(N^2);