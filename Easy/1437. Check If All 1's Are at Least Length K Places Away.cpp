// Problem Link: https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/description/?envType=daily-question&envId=2025-11-17

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n=nums.size();
        nums[0]*=nums[0]?-1:1;
        for(int i=1;i<n;i++){
            int mul=nums[i]?-1:1;
            nums[i]+=abs(nums[i-1]);
            nums[i]*=mul;
        }
        for(int i=0;i<n-k;i++){
            if(nums[i]<0 && abs(nums[i+k])-abs(nums[i]))return 0;
        }
        
        return abs(nums[n-1])<=1 || (k<n && abs(nums[n-1])-abs(nums[n-k-1])<=1);
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);