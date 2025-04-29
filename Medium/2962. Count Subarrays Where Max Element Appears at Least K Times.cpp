// Problem Link: https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/?envType=daily-question&envId=2025-04-29

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans=0,i=0,j=0,n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        int cnt=0;
        while(j<n){
            if(nums[j++]==mx)cnt++;
            while(i<n && cnt>=k){
                ans+=n-j+1;
                if(nums[i++]==mx)cnt--;
            }
        }
        return ans;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(1);