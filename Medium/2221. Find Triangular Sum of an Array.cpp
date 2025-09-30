// Problem Link: https://leetcode.com/problems/find-triangular-sum-of-an-array/description/

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        while(n--){
            for(int i=0;i<n;i++){
                nums[i]=(nums[i]+nums[i+1])%10;
            }
        }
        return nums[0];
    }
};

// Time Complexity : O(N^2);
// Space Complexity: O(1);