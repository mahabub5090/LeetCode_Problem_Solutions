// Problem Link: https://leetcode.com/problems/count-partitions-with-max-min-difference-at-most-k/description/?envType=daily-question&envId=2025-12-06

class Solution {
    using ll=long long;
public:
    int countPartitions(vector<int>& nums, int k) {
        int i=0,j=0,n=nums.size(),mod=1e9+7;
        vector<ll>dp(n+1),pref(n+1);
        deque<int>mn,mx;
        dp[0]=pref[0]=1;

        for(int i=0,j=0;i<n;i++){
            while(mx.size() && nums[mx.back()]<=nums[i])mx.pop_back();
            mx.push_back(i);

            while(mn.size() && nums[mn.back()]>=nums[i])mn.pop_back();
            mn.push_back(i);

            while(mx.size() && mn.size() && nums[mx.front()]-nums[mn.front()]>k){
                if(mx.front()==j)mx.pop_front();
                if(mn.front()==j)mn.pop_front();
                j++;
            }

            dp[i+1]=pref[i]-(j>0?pref[j-1]:0)+mod;
            dp[i+1]%=mod;

            pref[i+1]=pref[i]+dp[i+1];
            pref[i+1]%=mod;
        }
        return dp[n];
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);