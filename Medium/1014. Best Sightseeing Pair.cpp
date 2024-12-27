// Problem Link: https://leetcode.com/problems/best-sightseeing-pair/description/?envType=daily-question&envId=2024-12-27

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans=0,mx=values[0]-1;
        for(int i=1;i<values.size();i++){
            ans=max(ans,values[i]+mx);
            mx=max(mx-1,values[i]-1);
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);