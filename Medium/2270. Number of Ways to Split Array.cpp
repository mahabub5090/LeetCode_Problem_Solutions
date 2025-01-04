// Problem Link: https://leetcode.com/problems/number-of-ways-to-split-array/description/?envType=daily-question&envId=2025-01-03

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long>pref(n,0),suff(n,0);
        pref[0]=nums[0],suff[n-1]=nums[n-1];
        for(int i=1;i<n;i++)pref[i]+=pref[i-1]+nums[i];
        for(int i=n-2;i>=0;i--)suff[i]+=suff[i+1]+nums[i];
        int ans=0;
        for(int i=0;i<n-1;i++){
            ans+=pref[i]>=suff[i+1];
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);