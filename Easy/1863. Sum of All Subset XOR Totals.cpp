// Problem Link: https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/?envType=daily-question&envId=2025-04-05

// class Solution {
// public:
//     int ans(vector<int>& nums, int level, int currentXOR) {

//         if (level == nums.size()) return currentXOR;

//         int include = ans(nums, level + 1, currentXOR ^ nums[level]);

//         int exclude = ans(nums, level + 1, currentXOR);

        

//         return include + exclude;

//     } 
    
//     int subsetXORSum(vector<int>& nums) {
//         return ans(nums,0,0);
//     }
// };

// Time Complexity : O(2^N);
// Space Complexity: O(N);

// Way: 2 =>

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans=0;
        for(auto &c:nums)ans|=c;
        return ans<<(nums.size()-1);
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);