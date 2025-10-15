// Problem Link: https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/description/?envType=daily-question&envId=2025-10-15

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int ans=0,prev=0,cnt=1,n=nums.size();

        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1])cnt++;
            else{
                prev=cnt;
                cnt=1;
            }
            ans=max(ans,min(prev,cnt));
            ans=max(ans,cnt/2);
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);