// Problem Link: https://leetcode.com/problems/special-array-i/description/?envType=daily-question&envId=2025-02-01

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]%2==nums[i+1]%2)return 0;
        }
        return 1;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);