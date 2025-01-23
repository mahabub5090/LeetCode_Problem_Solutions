// Problem Link: https://leetcode.com/problems/count-servers-that-communicate/description/?envType=daily-question&envId=2025-01-23

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int>row(n),col(m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                row[i]+=grid[i][j];
                col[j]+=grid[i][j];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(row[i]>1 &&  col[j]>1 && grid[i][j])ans+=-1;
            }
        }
        for(auto &c:row)if(c>1)ans+=c;
        for(auto &c:col)if(c>1)ans+=c;
        return ans;
    }
};

// Time Complexity : O((N*M)+N+M) => O(N^2); 
// Space Complexity: O(N+M) => O(N);