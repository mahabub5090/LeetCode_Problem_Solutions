// Problem Link: https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/description/?envType=daily-question&envId=2025-03-19

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n-2;i++){
            if(nums[i]==0){
                ans++;
                for(int j=i+1;j<i+3;j++){
                    nums[j]=!nums[j];
                }
            }
        }
        if(nums[n-1]==0 || nums[n-2]==0)return -1;
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);