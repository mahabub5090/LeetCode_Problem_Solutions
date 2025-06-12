// Problem Link: https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/description/?envType=daily-question&envId=2025-06-12

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int ans=0,n=nums.size();
        for(int i=0;i<n;i++){
            ans=max(ans,abs(nums[i]-nums[(i+1)%n]));
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1); 