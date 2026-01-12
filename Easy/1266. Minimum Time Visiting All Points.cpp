// Problem Link: https://leetcode.com/problems/minimum-time-visiting-all-points/description/?envType=daily-question&envId=2026-01-12

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        auto prev=points[0];
        int ans=0;
        for(auto &c:points){
            ans+=max(abs(c[0]-prev[0]),abs(c[1]-prev[1]));
            prev=c;
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(2) => O(1);