// Problem Link: https://leetcode.com/problems/xor-after-range-multiplication-queries-i/description/?envType=daily-question&envId=2026-04-08

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int mod=1e9+7;
        for(auto &c:queries){
            int l=c[0],r=c[1],k=c[2],v=c[3];
            for(int i=l;i<=r;i+=k){
                nums[i]=(1ll*nums[i]*v)%mod;
            }
        }
        int ans=0;
        for(auto &c:nums)ans^=c;
        return ans;
    }
};

// Time Complexity : O(Q*N) => O(N^2);
// Space Complexity: O(1);
// Q = queries.size();