// Problem Link: https://leetcode.com/problems/count-partitions-with-even-sum-difference/description/?envType=daily-question&envId=2025-12-05

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int tt=accumulate(nums.begin(),nums.end(),0);
        int sum=0,ans=0;
        for(int i=0;i<nums.size()-1;i++){
            tt-=nums[i];
            sum+=nums[i];
            ans+=abs(tt-sum)%2==0;
        }
        return ans;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(1);