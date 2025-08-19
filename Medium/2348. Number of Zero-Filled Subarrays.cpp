// Problem Link: https://leetcode.com/problems/number-of-zero-filled-subarrays/description/?envType=daily-question&envId=2025-08-19

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt=0;
        int i=0,j=0,n=nums.size();
        int index=-1;
        while(j<n){
            if(nums[j])index=j;
            j++;
            if(index==-1)cnt+=j-i;
            else i=j,index=-1;
        }
        return cnt;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);