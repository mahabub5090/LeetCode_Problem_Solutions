// Problem Link: https://leetcode.com/problems/neighboring-bitwise-xor/description/?envType=daily-question&envId=2025-01-17

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xr=0;
        for(auto &c:derived)xr^=c;
        return xr==0;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);