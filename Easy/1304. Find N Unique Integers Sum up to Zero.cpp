// Problem Link: https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/description/?envType=daily-question&envId=2025-09-07

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        if(n%2)ans.push_back(0);
        for(int i=1;i<n;i+=2)ans.push_back(i),ans.push_back(-i);
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);
