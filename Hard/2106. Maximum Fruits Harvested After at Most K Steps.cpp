// Problem Link: https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/description/?envType=daily-question&envId=2025-08-03

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n=2*2e5+2;
        vector<int>pref(n,0);
        for(auto &c:fruits)pref[c[0]]=c[1];
        for(int i=1;i<n;i++)pref[i]+=pref[i-1];
        
        int ans=0,l=startPos,r=n-startPos;
        for(int i=0;i<=min(l,k);i++){
            int cnt=pref[min(n-1,startPos+max(0,k-2*i))]-(startPos-i-1<0?0:pref[startPos-i-1]);

            ans=max(ans,cnt);
        }
        for(int i=0;i<=min(r,k);i++){
            int cnt=pref[startPos+i]-((startPos-max(0,k-2*i))-1<0?0:pref[startPos-max(0,k-2*i)-1]);
            ans=max(ans,cnt);
        }
        return ans;
    }
};

// Time Complexity : O(2*N+2*K) => O(N);
// Space Complexity: O(N);