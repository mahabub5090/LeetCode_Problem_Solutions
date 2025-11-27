// Problem Link: https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/description/?envType=daily-question&envId=2025-11-27

class Solution {
public:
    using ll=long long;
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        ll ans=LLONG_MIN;
        vector<ll>pref(k,1e18);
        pref[k-1]=0;
        ll sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            ans=max(ans,sum-pref[i%k]);
            pref[i%k]=min(pref[i%k],sum);
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(K) => O(N);