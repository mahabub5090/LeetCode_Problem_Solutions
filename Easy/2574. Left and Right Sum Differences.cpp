// Problem Link: https://leetcode.com/problems/left-and-right-sum-differences/description/?envType=daily-question&envId=2026-06-06

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> suff(n,0),ans(n,0);
        for(int i=n-1;i>=0;i--){
            suff[i]=(i+1>=n?0:nums[i+1])+(i+1>=n?0:suff[i+1]);
        }

        int pref=0;
        for(int i=0;i<n;i++){
            ans[i]=abs(pref-suff[i]);
            pref+=nums[i];
        }
        return ans;
    }
};

// Time Complexity : O(N) + O(N) => O(N);
// Space Complexity: O(N) + O(N) => O(N);