// Problem Link: https://leetcode.com/problems/maximum-width-ramp/description/?envType=daily-question&envId=2024-10-10

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int i=0,j=0,n=nums.size(),ans=0;
        vector<int>mx(n);
        for(int i=n-1;i>=0;i--)mx[i]=max(nums[i],i==n-1?0:mx[i+1]);
        while(j<n){
            while(j<n && mx[j]>=nums[i])j++;
            i++;
            ans=max(ans,j-i);
        }
        return ans;
    }
};

// Time Complexity : O(2*N);
// Space Complexity: O(N);
