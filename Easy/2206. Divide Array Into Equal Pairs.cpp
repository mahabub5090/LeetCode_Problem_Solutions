// Problem Link: https://leetcode.com/problems/divide-array-into-equal-pairs/description/?envType=daily-question&envId=2025-03-17

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        vector<int>vc(mx+1,0);
        for(auto &c:nums)vc[c]++;
        for(auto &c:vc)if(c%2)return 0;
        return 1;
    }
};

// Time Complexity : O(3*N) => O(N);
// Space Complexity: O(N);