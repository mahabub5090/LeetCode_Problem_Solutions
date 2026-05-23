// Problem Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/?envType=daily-question&envId=2025-02-02
// Problem Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/?envType=daily-question&envId=2026-05-23

// class Solution {
// public:
//     bool check(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>vc;
//         for(auto &c:nums)vc.push_back(c);
//         for(auto &c:nums)vc.push_back(c);
//         for(int i=0;i<n;i++){
//             if(is_sorted(vc.begin()+i,vc.begin()+i+n))return 1;
//         }
//         return 0;
//     }
// };

// Time Complexity : O(2*N) + O(N*N) => O(N^2);
// Time Complexity : O(2*N) => O(N);

// Way: 2 =>

class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt=0, n=nums.size();
        for(int i=0;i<n-1;i++) cnt+=nums[i]>nums[i+1];
        return cnt<=1 && (cnt?nums[0]>=nums[n-1]:1);
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);