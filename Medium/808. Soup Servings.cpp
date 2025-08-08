// Problem Link: https://leetcode.com/problems/soup-servings/description/?envType=daily-question&envId=2025-08-08

class Solution {
public:
    unordered_map<int,unordered_map<int,double>>dp;
    double calculate(int i,int j){
        if(i<=0 && j<=0)return 0.5;
        if(i<=0)return 1;
        if(j<=0)return 0;
        if(dp[i].count(j))return dp[i][j];

        return dp[i][j]=(calculate(i-4,j)+calculate(i-3,j-1)+calculate(i-2,j-2)+calculate(i-1,j-3))/4;
    }
    double soupServings(int n) {
        int m=n/25+(n%25!=0);
        for(int i=1;i<=m;i++){
            if(calculate(i,i)>1-(1e-5))return 1;
        }
        return calculate(m,m);
    }
};

// Time Complexity : O(1);
// Space Complexity: O(1);
// Why this solution's Time Complexity and Space complexity both are O(1),not O(N^2)? Cause, in this problem if the N is greater than 5,000 then we immediately return 1.