// Problem Link: https://leetcode.com/problems/partition-array-according-to-given-pivot/description/?envType=daily-question&envId=2025-03-03

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>ans;
        for(auto &c:nums)if(c<pivot)ans.push_back(c);
        for(auto &c:nums)if(c==pivot)ans.push_back(c);
        for(auto &c:nums)if(c>pivot)ans.push_back(c);
        return ans;
    }
};

// Time Complexity : O(3*N) => O(N);
// Space Complexity: O(N);