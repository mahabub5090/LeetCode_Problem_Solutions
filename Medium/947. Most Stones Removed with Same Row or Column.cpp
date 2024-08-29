// Problem Link: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/?envType=daily-question&envId=2024-08-29

class Solution {
public:
    void dfs(int src,auto &adj,auto &vis){
        vis[src]=1;
        for(auto &child:adj[src]){
            if(vis[child]==0)dfs(child,adj,vis);
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0)dfs(i,adj,vis),cnt++;
        }
        return n-cnt;
    }
};

// Time Complexity : O(N*N)+O(N*N) => O(N^2);
// Space Complexity: O(N*N)+O(N) => O(N^2);