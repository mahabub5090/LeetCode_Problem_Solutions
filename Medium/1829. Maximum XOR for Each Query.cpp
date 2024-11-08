// Problem Link: https://leetcode.com/problems/maximum-xor-for-each-query/submissions/1446327111/?envType=daily-question&envId=2024-11-08

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xr=0;
        for(auto &c:nums)xr^=c;
        vector<int>ans;
        int mask=(1<<maximumBit)-1;
        for(int i=nums.size()-1;i>=0;i--){
            ans.push_back(xr^mask);
            xr^=nums[i];
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);