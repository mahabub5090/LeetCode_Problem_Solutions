// Problem Link: https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/submissions/1476272303/?envType=daily-question&envId=2024-12-11

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int l=0,r=0;
        while(r<nums.size()){
            while(nums[r]-nums[l]>2*k)l++;
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(1);