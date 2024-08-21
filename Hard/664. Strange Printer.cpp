// Problem Link: https://leetcode.com/problems/strange-printer/description/?envType=daily-question&envId=2024-08-21

class Solution {
public:
    vector<vector<int>>dp=vector<vector<int>>(101,vector<int>(101,-1));     

    int solve(int i,int j,string &s){
        if(i==j)return 1;
        if(dp[i][j]!=-1)return dp[i][j];

        int turns=1e9;
        for(int k=i;k<j;k++){
            turns=min(turns,solve(i,k,s)+solve(k+1,j,s));
        }
        if(s[i]==s[j])turns--;
        return dp[i][j]=turns;

    }
    int strangePrinter(string s) {
        return solve(0,s.size()-1,s);
    }
};

// Time Complexity : O((101^2)*101) => O(100^3) => O(N^3); 
// Space Complexity: O(101*101) + O(100) => 100^2 => O(N^2);
// Max piles size is 100 (max N);
