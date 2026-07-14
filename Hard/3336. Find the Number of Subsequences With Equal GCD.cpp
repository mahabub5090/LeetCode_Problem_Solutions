// Problem Link: https://leetcode.com/problems/find-the-number-of-subsequences-with-equal-gcd/description/?envType=daily-question&envId=2026-07-14

class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int n=nums.size(), mod=1e9+7;
        int mx=*max_element(nums.begin(),nums.end());

        vector<vector<int>> dp(mx+1,vector<int>(mx+1));
        dp[0][0]=1;

        for(auto &c:nums){
            vector<vector<int>> ndp(mx+1,vector<int>(mx+1));

            for(int j=0;j<=mx;j++){
                int div=__gcd(j,c);

                for(int k=0;k<=mx;k++){
                    int val=dp[j][k];
                    if(val==0) continue;

                    int div2=__gcd(k,c);

                    ndp[j][k]+=val;
                    ndp[j][k]%=mod;

                    ndp[div][k]+=val;
                    ndp[div][k]%=mod;

                    ndp[j][div2]+=val;
                    ndp[j][div2]%=mod;
                }
            }

            dp=ndp;
        }

        int ans=0;
        for(int j=1;j<=mx;j++) ans+=dp[j][j], ans%=mod;
        return ans;
    }
};

// Time Complexity : O(N) + O(N*((M*M*logM)+(M*M))) + O(M) => O(N*(M^2)*logM);
// Space Complexity: O(M*M) => O(M^2);
// M = max(nums[i]);