// Problem Link: https://leetcode.com/problems/xor-after-range-multiplication-queries-ii/description/?envType=daily-question&envId=2026-04-09

class Solution {
public:
    int mod=1e9+7;
    int pow(long long x,long long y){
        long long ans=1;
        while(y){
            if(y&1)ans=(ans*x)%mod;
            x=(x*x)%mod;
            y>>=1;
        }
        return ans;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size(),root=sqrt(n);
        vector<vector<vector<int>>>groups(root);
        for(auto &c:queries){
            int l=c[0],r=c[1],k=c[2],v=c[3];
            if(k<root)groups[k].push_back({l,r,v});
            else {
                for(int i=l;i<=r;i+=k){
                    nums[i]=(1ll*nums[i]*v)%mod;
                }
            }
        }

        vector<long long>diff(n+root);
        for(int k=1;k<root;k++){
            if(groups[k].empty())continue;

            fill(diff.begin(),diff.end(),1);
            for(auto &c:groups[k]){
                int l=c[0],r=c[1],v=c[2];
                diff[l]=(diff[l]*v)%mod;
                int R=((r-l)/k+1)*k+l;
                diff[R]=diff[R]*pow(v,mod-2)%mod;
            }

            for(int i=k;i<n;i++){
                diff[i]=(diff[i]*diff[i-k])%mod;
            }
            for(int i=0;i<n;i++){
                nums[i]=(1ll*nums[i]*diff[i])%mod;
            }
        }

        int ans=0;
        for(auto &c:nums)ans^=c;
        return ans;
    }
};

// Time Complexity : O((N+Q)*sqrt(N)) => O(N*sqrt(N));
// Space Complexity: O(N+Q) => O(N);
// Q = queries.size();