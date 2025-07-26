// Problem Link: https://leetcode.com/problems/maximize-subarrays-after-removing-one-conflicting-pair/description/?envType=daily-question&envId=2025-07-26

class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<int>bmin(n+1,INT_MAX),bmin2(n+1,INT_MAX);
        for(auto &c:conflictingPairs){
            int a=min(c[0],c[1]),b=max(c[0],c[1]);
            if(bmin[a]>b){
                bmin2[a]=bmin[a];
                bmin[a]=b;
            }
            else if(bmin2[a]>b) bmin2[a]=b;
        }

        long long ans=0;
        int ib=n,b=INT_MAX;
        vector<long long>delCount(n+1,0);
        long long mx=0;

        for(int i=n;i>=1;i--){
            if(bmin[ib]>bmin[i]){
                b=min(b,bmin[ib]);
                ib=i;
            }
            else b=min(b,bmin[i]);

            ans+=min(bmin[ib],n+1)-i;
            delCount[ib]+=min(min(b,bmin2[ib]),(n+1))-min(bmin[ib],n+1);
            mx=max(mx,delCount[ib]);
        }

        return ans+mx;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);