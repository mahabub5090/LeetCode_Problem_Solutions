// Problem Link: https://leetcode.com/problems/stone-game-v/description/?envType=daily-question&envId=2026-08-17

class Solution {
public:
    vector<vector<int>> dp;
    vector<int> pref;

    int dfs(auto &vc,int l,int r){
        if(l==r) return 0;
        if(dp[l][r]) return dp[l][r];

        int sum=pref[r+1]-pref[l];
        int sumLeft=0;

        for(int i=l;i<r;i++){
            sumLeft+=vc[i];
            int sumRight=sum-sumLeft;

            if(sumLeft<sumRight){
                int newVal=dfs(vc,l,i)+sumLeft;
                dp[l][r]=max(dp[l][r],newVal);
            }
            else if(sumLeft>sumRight){
                int newVal=dfs(vc,i+1,r)+sumRight;
                dp[l][r]=max(dp[l][r],newVal);
            }
            else{
                int newVal=max(dfs(vc,l,i),dfs(vc,i+1,r))+sumLeft;
                dp[l][r]=max(dp[l][r],newVal);
            }
        }
        return dp[l][r];
    }


    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        dp.assign(n,vector<int>(n,0));
        pref.assign(n+1,0);
        for(int i=1;i<=n;i++) pref[i]+=pref[i-1]+stoneValue[i-1];
        return dfs(stoneValue,0,n-1);
    }
};

// Time Complexity : O(N*N) + O(N) + O((N*N)*N) => O(N^3);
// Space Complexity: O(N*N) + O(N) + O(N) => O(N^2); // Recursion stack is also O(N);