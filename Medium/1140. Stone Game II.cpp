// Problem Link: https://leetcode.com/problems/stone-game-ii/description/?envType=daily-question&envId=2024-08-20
// Problem Link: https://leetcode.com/problems/stone-game-ii/description/?envType=daily-question&envId=2026-08-09

class Solution {
public:
    int dp[2][101][101];
    int dfs(int turn,int i,int m,auto &vc){
        int n=vc.size();
        if(i==n) return 0;
        if(dp[turn][i][m]!=-1)return dp[turn][i][m];

        int ans=(turn==0?0:INT_MAX);
        int tt=0;
        for(int j=1;j<=2*m && i+j<=n;j++){
            tt+=vc[i+j-1];
            int rest=dfs(!turn,i+j,max(j,m),vc);

            if(turn==0) ans=max(ans,tt+rest);
            else ans=min(ans,rest);
        }
        return dp[turn][i][m]=ans;
    }


    int stoneGameII(vector<int>& piles) {   
        memset(dp, -1, sizeof(dp));    
        return dfs(0,0,1,piles);
    }
};

// Time Complexity : O(2*(N^2)) + O(2*(N^2)*N) => O(N^3); 
// Space Complexity: O(2*(N^2)) + O(N) => O(N^2); // O(N) for recursion stack;
// N <= 100;