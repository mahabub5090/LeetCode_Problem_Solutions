// Problem Link: https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/description/?envType=daily-question&envId=2026-05-29

class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans=INT_MAX;
        for(auto &c:nums){
            int sum=0;
            while(c)sum+=c%10,c/=10;
            ans=min(ans,sum);
        }
        return ans;
    }
};

// Time Complexity : O(NlogD);
// Space Complexity: O(1);
// D = max(nums[i]);