// Problem Link: https://leetcode.com/problems/trionic-array-i/description/?envType=daily-question&envId=2026-02-03

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i=1,n=nums.size();
        while(i<n && nums[i-1]<nums[i])i++;
        if(i==1 || i==n)return 0;
        while(i<n && nums[i-1]>nums[i])i++;
        if(i==n)return 0;
        while(i<n && nums[i-1]<nums[i])i++;
        return i==n;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);