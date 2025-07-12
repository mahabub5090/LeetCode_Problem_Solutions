// Problem Link: https://leetcode.com/problems/the-earliest-and-latest-rounds-where-players-compete/description/?envType=daily-question&envId=2025-07-12

class Solution {
public:
    int F[30][30][30],G[30][30][30];
    pair<int,int> dp(int n,int f,int s){
        if(F[n][f][s])return {F[n][f][s],G[n][f][s]};
        if(f+s==n+1)return {1,1};
        if(f+s>n+1){
            tie(F[n][f][s],G[n][f][s])=dp(n,n+1-s,n+1-f);
            return {F[n][f][s],G[n][f][s]};
        }
        int earliest=INT_MAX,latest=INT_MIN;
        int nHalf=(n+1)/2;

        if(s<=nHalf){
            for(int i=0;i<f;i++){
                for(int j=0;j<s-f;j++){
                    auto [x,y]=dp(nHalf,i+1,i+j+2);
                    earliest=min(earliest,x);
                    latest=max(latest,y);
                }
            }
        }
        else{
            int sPrime=n+1-s;
            int mid=(n-(2*sPrime)+1)/2;
            for(int i=0;i<f;i++){
                for(int j=0;j<sPrime-f;j++){
                    auto [x,y]=dp(nHalf,i+1,i+j+2+mid);
                    earliest=min(earliest,x);
                    latest=max(latest,y);
                }
            }
        }

        return {F[n][f][s]=earliest+1,G[n][f][s]=latest+1};
    }
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        memset(F,0,sizeof(F));
        memset(G,0,sizeof(G));

        if(firstPlayer>secondPlayer)swap(firstPlayer,secondPlayer);

        auto [earliest,latest]=dp(n,firstPlayer,secondPlayer);
        return {earliest,latest};
    }
};

// Time Complexity : O(N^5);
// Space Complexity: O(N^3);