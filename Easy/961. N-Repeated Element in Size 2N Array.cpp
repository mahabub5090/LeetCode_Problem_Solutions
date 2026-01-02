// Problem Link: https://leetcode.com/problems/n-repeated-element-in-size-2n-array/description/?envType=daily-question&envId=2026-01-02

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int>st;
        for(auto &c:nums){
            if(st.count(c))return c;
            st.insert(c);
        }
        return 0;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);