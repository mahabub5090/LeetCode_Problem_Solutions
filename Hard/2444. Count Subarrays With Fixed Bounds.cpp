// Problem Link: https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/?envType=daily-question&envId=2025-04-26

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0,start=-1,mn=-1,mx=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minK || nums[i]>maxK)start=i;
            if(nums[i]==minK)mn=i;
            if(nums[i]==maxK)mx=i;
            int valid=max(0LL,min(mn,mx)-start);
            ans+=valid;
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space COmplexity: O(1);