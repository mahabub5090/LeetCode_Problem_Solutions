// Problem Link: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/?envType=daily-question&envId=2025-12-28

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;
        for(auto &c:grid){
            for(auto &cc:c)ans+=cc<0;
        }
        return ans;
    }
};

// Time Complexity : O(N*N) => O(N^2);
// Space Complexity: O(1);