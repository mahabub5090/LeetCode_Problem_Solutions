// Problem Link: https://leetcode.com/problems/solving-questions-with-brainpower/description/?envType=daily-question&envId=2025-04-01

class Solution {
public:
    vector<long long>dp;
    long long backtrack(int i,auto &vc){
        if(i>=vc.size())return 0;
        if(dp[i]!=-1)return dp[i];
        long long inc=vc[i][0]+backtrack(i+vc[i][1]+1,vc);
        long long skip=backtrack(i+1,vc);
        return dp[i]=max(inc,skip);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        dp.resize(questions.size(),-1);
        return backtrack(0,questions);
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);