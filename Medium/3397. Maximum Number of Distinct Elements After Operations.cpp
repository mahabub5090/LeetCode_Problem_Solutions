// Problem Link: https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/description/?envType=daily-question&envId=2025-10-18

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int prev=nums[0]-=k;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1])nums[i]=min(prev+1,nums[i]+k);
            else nums[i]=max(prev+1,nums[i]-k);
            prev=nums[i];
        }

        sort(nums.begin(),nums.end());
        int ans=1;
        prev=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=prev)ans++,prev=nums[i];
        }

        return ans;
    }
};

// Time Complexity : O(2*NlogN) + O(2*N) => O(NlogN);
// Space Complexity: O(1);