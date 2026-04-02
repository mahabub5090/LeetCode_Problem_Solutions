// Problem Link: https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/description/?envType=daily-question&envId=2026-04-02

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m=coins.size(),n=coins[0].size();
        vector memo(m,vector(n,vector<int>(3,INT_MIN)));

        auto dfs=[&](auto &self,int i,int j,int k){
            if(i>=m || j>=n)return INT_MIN;

            int c=coins[i][j];
            if(i==m-1 && j==n-1)return k>0?max(0,c):c;

            int ans=memo[i][j][k];
            if(ans!=INT_MIN)return ans;

            ans=max(self(self,i+1,j,k),self(self,i,j+1,k))+c;
            if(k>0 && c<0)ans=max({ans,self(self,i+1,j,k-1),self(self,i,j+1,k-1)});
            return memo[i][j][k]=ans;
        };
        return dfs(dfs,0,0,2);
    }
};

// Time Complexity : O(M*N) => O(N^2);
// Space Complexity: O(M*N) => O(N^2);