// Problem Link: https://leetcode.com/problems/apply-operations-to-an-array/description/?envType=daily-question&envId=2025-03-01

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int>ans;
        int cnt=0,n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]==0)cnt++;
            else if(nums[i]==nums[i+1])ans.push_back(nums[i]*2),nums[i+1]=0;
            else ans.push_back(nums[i]);
        }
        if(nums[n-1])ans.push_back(nums[n-1]);
        else cnt++;
        for(int i=0;i<cnt;i++)ans.push_back(0);
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);