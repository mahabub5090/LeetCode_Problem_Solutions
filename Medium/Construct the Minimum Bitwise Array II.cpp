// Problem Link: https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/description/?envType=daily-question&envId=2026-01-21

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for(auto &c:nums){
            int ans=-1;

            int bit=1;
            while((c&bit)!=0){
                ans=c-bit;
                bit<<=1;
            }

            c=ans;
        }
        return nums;
    }
};

// Time Complexity : O(N*max(nums[i])) => O(NlogN);
// Space Complexity: O(1);