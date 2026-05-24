// Problem Link: https://leetcode.com/problems/jump-game-v/description/?envType=daily-question&envId=2026-05-24

class Solution {
public:
    vector<int> dp;

    void dfs(int id,auto &arr,int d){
        int n=arr.size();

        if(dp[id]!=-1) return;
        dp[id]=1;

        for(int i=id-1; i>=0 && id-i<=d && arr[id]>arr[i]; i--){
            dfs(i,arr,d);
            dp[id]=max(dp[id],dp[i]+1);
        }
        for(int i=id+1; i<n && i-id<=d && arr[id]>arr[i]; i++){
            dfs(i,arr,d);
            dp[id]=max(dp[id],dp[i]+1);
        }
    }

    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        dp.resize(n,-1);

        for(int i=0;i<n;i++) dfs(i,arr,d);
        return *max_element(dp.begin(),dp.end());
    }
};

// Time Complexity : O(N*D) => O(N^2);
// Space Complexity: O(N);