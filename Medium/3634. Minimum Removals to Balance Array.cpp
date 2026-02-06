// Problem Link: https://leetcode.com/problems/minimum-removals-to-balance-array/description/?envType=daily-question&envId=2026-02-06

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=n,j=0;
        for(int i=0;i<n;i++){
            while(j<n && 1ll*nums[i]*k>=nums[j])j++;
            ans=min(ans,n-(j-i));
        }
        return ans;
    }
};

// Time complexity : O(NlogN) + O(NlogN) => O(NlogN);
// Space Complexity: O(N);