// Problem Link: https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/description/
// Problem Link: https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/description/?envType=daily-question&envId=2025-10-31

// class Solution {
// public:
//     vector<int> getSneakyNumbers(vector<int>& nums) {
//         vector<int>ans;
//         sort(nums.begin(),nums.end());
//         for(int i=0;i<nums.size()-1;i++)
//             if(nums[i]==nums[i+1])ans.push_back(nums[i]);
//         return ans;
//     }
// };

// // Time Complexity : O(NlogN + N) => O(NlogN);
// // Space Complexity: O(N);

// way: 2 =>

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>cnt(nums.size(),0);
        for(auto &c:nums)cnt[c]++;
        vector<int>ans;
        for(int i=0;i<cnt.size();i++)if(cnt[i]==2)ans.push_back(i);
        return ans;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(N);