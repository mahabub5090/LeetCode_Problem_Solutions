// Problem Link: https://leetcode.com/problems/minimum-total-distance-traveled/description/?envType=daily-question&envId=2024-10-31

class Solution {
public:
    long long minDist(int currR,int currF,auto &rb,auto &fact,auto &dp){
        if(currR==rb.size())return 0;
        if(currF==fact.size())return 1e18;
        if(dp[currR][currF]!=-1)return dp[currR][currF];
        long long fix=abs(rb[currR]-fact[currF])+minDist(currR+1,currF+1,rb,fact,dp);
        long long skip=minDist(currR,currF+1,rb,fact,dp);

        return dp[currR][currF]=min(fix,skip);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        vector<int>fact;
        for(auto &c:factory){
            for(int i=0;i<c[1];i++)
                fact.push_back(c[0]);
        }
        sort(robot.begin(),robot.end());
        sort(fact.begin(),fact.end());
        vector<vector<long long>>dp(robot.size(),vector<long long>(fact.size(),-1));
        return minDist(0,0,robot,fact,dp);
    }
};

// Time Complexity : O(N^2) + O(N^2) => O(N^2);
// Space Complexity: O(N^2);