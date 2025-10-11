// Problem Link: https://leetcode.com/problems/maximum-total-damage-with-spell-casting/description/?envType=daily-question&envId=2025-10-11

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int,int>mp;for(auto &c:power)mp[c]++;
        vector<pair<int,int>>vc={{INT_MIN,0}};
        for(auto &c:mp)vc.push_back(c);

        int n=vc.size();
        vector<long long>dp(n,0);

        long long mx=0;
        for(int i=1,j=1;i<n;i++){
            while(j<i && vc[j].first<vc[i].first-2){
                mx=max(mx,dp[j]);
                j++;
            }
            dp[i]=mx+(1ll*vc[i].first*vc[i].second);
        }

        long long ans=*max_element(dp.begin(),dp.end());
        return ans;
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(N);