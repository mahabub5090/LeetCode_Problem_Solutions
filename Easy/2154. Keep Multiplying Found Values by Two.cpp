// Problem Link: https://leetcode.com/problems/keep-multiplying-found-values-by-two/description/?envType=daily-question&envId=2025-11-19

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int>st;
        for(auto &c:nums)st.insert(c);
        while(st.count(original))original*=2;
        return original;
    }
};


// Time Complexity : O(N);
// Space Complexity: O(N);