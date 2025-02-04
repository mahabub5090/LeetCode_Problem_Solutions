// Problem Link: https://leetcode.com/problems/maximum-ascending-subarray-sum/description/?envType=daily-question&envId=2025-02-04

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans=0,sum=nums[0],i=0,j=1,n=nums.size();

        while(j<n){
            if(nums[j]>nums[j-1])sum+=nums[j++];
            else{
                ans=max(ans,sum);
                sum=nums[j];
                i=j++;
            }
        }  
        ans=max(ans,sum); 
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);