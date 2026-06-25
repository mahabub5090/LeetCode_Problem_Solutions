// Problem Link: https://leetcode.com/problems/count-subarrays-with-majority-element-i/description/?envType=daily-question&envId=2026-06-25

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans=0, n=nums.size();
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=i;j<n;j++){
                if(nums[j]==target) cnt++;
                if(cnt>(j-i+1)/2) ans++;
            }
        }
        return ans;
    }
};

// Time Complexity : O(N*N) => O(N^2);
// Space Complexity: O(1);