// Problem Link: https://leetcode.com/problems/equal-sum-grid-partition-i/description/?envType=daily-question&envId=2026-03-25

class Solution {
public:
    using ll = long long;

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<ll>rows(m,0),cols(n,0);

        for(int i=0;i<m;i++)rows[i]=accumulate(grid[i].begin(),grid[i].end(),0ll)+(i>0?rows[i-1]:0);;
        
        for(int i=0;i<n;i++){
            ll sum=0;
            for(int j=0;j<m;j++)sum+=grid[j][i];
            cols[i]=sum+(i>0?cols[i-1]:0);
        }

        for(int i=0;i<m;i++)if(rows[i]==rows[m-1]-rows[i])return 1;
        for(int i=0;i<n;i++)if(cols[i]==cols[n-1]-cols[i])return 1;

        return 0;
    }
};

// Time Complexity : O(M*N) + O(M*N) + O(M) + O(N) => O(N^2);
// Space Complexity: O(M)+ O(N) => O(N);