// Problem Link: https://leetcode.com/problems/grid-game/description/?envType=daily-question&envId=2025-01-21

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();
        vector<long long>pref(n,0),pref2(n,0);
        pref[0]=grid[0][0];
        pref2[0]=grid[1][0];
        for(int i=1;i<n;i++){
            pref[i]+=pref[i-1]+grid[0][i];
            pref2[i]+=pref2[i-1]+grid[1][i];
        }
        long long ans=LLONG_MAX;
        for(int i=0;i<n;i++){
            long long second=max(pref[n-1]-pref[i],i==0?0:pref2[i-1]);
            ans=min(ans,second);
        }
        return ans;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(2*N) => O(N); 