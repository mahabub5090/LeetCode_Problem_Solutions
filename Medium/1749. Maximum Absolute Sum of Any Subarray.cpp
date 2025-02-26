// Problem Link: https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/description/?envType=daily-question&envId=2025-02-26

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int mx=0,mn=0,sum=0,ans=0;
        for(auto &c:nums){
            sum+=c;
            ans=max({ans,abs(sum-mx),abs(sum-mn)});
            mx=max(mx,sum);
            mn=min(mn,sum);
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);