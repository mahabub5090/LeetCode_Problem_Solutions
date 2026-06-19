// Problem Link: https://leetcode.com/problems/find-the-highest-altitude/description/?envType=daily-question&envId=2026-06-19

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0, curr=0;
        for(auto &c:gain){
            curr+=c;
            ans=max(ans,curr);
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);