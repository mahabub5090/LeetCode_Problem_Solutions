// Problem Link: https://leetcode.com/problems/build-array-from-permutation/description/?envType=daily-question&envId=2025-05-06

// class Solution {
// public:
//     vector<int> buildArray(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>ans(n,0);
//         for(int i=0;i<n;i++){
//             ans[i]=nums[nums[i]];
//         }
//         return ans;
//     }
// };

// // Time Complexity : O(N);
// // Space Complexity: O(N);

// Way:02 => 
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        for(auto &c:nums)c+=1000*(nums[c]%1000);
        for(auto &c:nums)c/=1000;
        return nums;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(1);