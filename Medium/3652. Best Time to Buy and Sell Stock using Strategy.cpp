// Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-using-strategy/description/?envType=daily-question&envId=2025-12-18

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size();
        vector<long long>pref(n+1),pref2(n+1);
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+prices[i]*strategy[i];
            pref2[i+1]=pref2[i]+prices[i];
        }

        long long ans=pref[n];

        for(int i=k-1;i<n;i++){
            long long lp=pref[i-k+1],rp=pref[n]-pref[i+1];

            long long change=pref2[i+1]-pref2[i-k/2+1];

            ans=max(ans,lp+change+rp);
        }
        return ans;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(2*N) => O(N);