// Problem Link: https://leetcode.com/problems/bitwise-xor-of-all-pairings/description/?envType=daily-question&envId=2025-01-16

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        if(nums2.size()%2)for(auto &c:nums1)ans^=c;
        if(nums1.size()%2)for(auto &c:nums2)ans^=c;
        return ans;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(1);