// Problem Link: https://leetcode.com/problems/find-the-maximum-number-of-fruits-collected/description/?envType=daily-question&envId=2025-08-07

class Solution {
public:
    int dp(auto &fruits){
        int n=fruits.size();
        vector<int>prev(n,INT_MIN),curr(n,INT_MIN);

        prev[n-1]=fruits[0][n-1];
        for(int i=1;i<n-1;i++){
            for(int j=max(n-1-i,i+1);j<n;j++){
                int best=prev[j];
                if(j-1>=0)best=max(best,prev[j-1]);
                if(j+1<n)best=max(best,prev[j+1]);          
                curr[j]=best+fruits[i][j];
            }
            swap(prev,curr);
        }
        return prev[n-1];
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n=fruits.size();
        int ans=0;
        for(int i=0;i<n;i++)ans+=fruits[i][i];
        ans+=dp(fruits);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++)swap(fruits[i][j],fruits[j][i]);
        }
        ans+=dp(fruits);
        return ans;
    }
};

// Time Complexity : O(3*(N^2)) => O(N^2);
// Space Complexity: O(N);