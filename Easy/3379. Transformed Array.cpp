// Problem Link: https://leetcode.com/problems/transformed-array/description/?envType=daily-question&envId=2026-02-05

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int val=nums[(((i+nums[i])%n)+n)%n];
            ans.push_back(val);
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);