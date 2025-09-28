// Problem Link: https://leetcode.com/problems/largest-perimeter-triangle/description/?envType=daily-question&envId=2025-09-28

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]<nums[i+1]+nums[i+2])return nums[i]+nums[i+1]+nums[i+2];
        }
        return 0;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);
