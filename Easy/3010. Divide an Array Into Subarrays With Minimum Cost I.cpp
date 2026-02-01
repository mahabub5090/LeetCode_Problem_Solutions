// Problem Link: https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/description/?envType=daily-question&envId=2026-02-01

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int a=INT_MAX,b=INT_MAX;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<a)a=nums[i];
            if(a<b)swap(a,b);
        }
        return nums[0]+a+b;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);