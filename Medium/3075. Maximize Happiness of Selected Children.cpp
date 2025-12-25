// Problem Link: https://leetcode.com/problems/maximize-happiness-of-selected-children/description/?envType=daily-question&envId=2025-12-25

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(),happiness.rend());
        long long tt=0;
        for(int i=0;i<k;i++)tt+=max(0,happiness[i]-i);
        return tt;
    }
};

// Time Complexity : O(NlogN) + O(N) => O(NlogN);
// Space Complexity: O(1);