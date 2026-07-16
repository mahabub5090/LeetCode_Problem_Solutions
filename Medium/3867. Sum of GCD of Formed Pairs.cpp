// Problem Link: https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/description/?envType=daily-question&envId=2026-07-16

class Solution {
public:
    using ll = long long;

    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<ll> prefGrid(n,0);
        int mx=0;
        for(int i=0;i<n;i++) mx=max(mx,nums[i]), prefGrid[i]=__gcd(nums[i],mx);
        sort(prefGrid.begin(),prefGrid.end());

        ll ans=0;
        for(int i=0;i<n/2;i++) ans+=__gcd(prefGrid[i],prefGrid[n-i-1]);
        return ans;
    }
};

// Time Compelxity : O(N*logM) + O(NlogN) + O((N/2)*logM) => O(NlogN) + O(NlogM); 
// Space Complexity: O(N);
// M = max(nums[i]);