// Problem Link: https://leetcode.com/problems/triangle/description/?envType=daily-question&envId=2025-09-25

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp=triangle;
        dp[0][0]=triangle[0][0];
        for(int i=1;i<triangle.size();i++){
            dp[i][0]+=dp[i-1][0];
            for(int j=1;j<triangle[i].size()-1;j++){
                dp[i][j]+=min(dp[i-1][j-1],dp[i-1][j]);
            }
            dp[i][i]+=dp[i-1][i-1];
        }
        
        int ans=dp.back()[0];
        for(auto &c:dp.back())ans=min(ans,c);
        return ans;
    }
};

// Time Complexity : O(N^2);
// Space Complexity: O(N^2);