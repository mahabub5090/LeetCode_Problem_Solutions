// Problem Link: http://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/editorial/?envType=daily-question&envId=2025-07-29

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>pos(32,-1),ans(n);
        for(int i=n-1;i>=0;i--){
            int j=i;
            for(int bit=0;bit<32;bit++){
                if(nums[i]&(1<<bit))pos[bit]=i;
                else if(pos[bit]!=-1)j=max(j,pos[bit]);
            }
            ans[i]=j-i+1;
        }
        return ans;
    }
};

// Time Complexity : O(N*32) => O(N);
// Space Complexity: O(32) => O(1);