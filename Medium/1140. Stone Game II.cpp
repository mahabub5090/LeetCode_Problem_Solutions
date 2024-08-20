// Problem Link: https://leetcode.com/problems/stone-game-ii/description/?envType=daily-question&envId=2024-08-20

class Solution {
public:
    int dp[2][101][101];

    int dfs(char c,int i,int m,auto &vc){
        if(i==vc.size()) return 0;
        if(dp[c-'a'][i][m]!=-1)return dp[c-'a'][i][m];

        int ans=(c=='a'?0:1e9);
        int tt=0;
        for(int j=0;j<2*m;j++){
            if(i+j==vc.size())break;
            tt+=vc[i+j];
            if(c=='a'){
                ans=max(ans,tt+dfs('b',i+j+1,max(j+1,m),vc));
            }
            else ans=min(ans,dfs('a',i+j+1,max(j+1,m),vc));
        }
        return dp[c-'a'][i][m]=ans;
    }

    int stoneGameII(vector<int>& piles) {   
        memset(dp, -1, sizeof(dp));    
        return dfs('a',0,1,piles);
    }
};

// Time Complexity : O((101^2)*101) => O(100^3) => O(N^3); 
// Space Complexity: O(2*101*101) + O(100) => 100^2 => O(N^2);
// Max piles size is 100 (max N);