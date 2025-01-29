// Problem Link: https://leetcode.com/problems/redundant-connection/description/?envType=daily-question&envId=2025-01-29

class Solution {
public:
    bool dfs(int curr,int target,auto &vis,auto &adj){
        if(curr==target)return 1;
        vis[curr]=1;

        for(auto &c:adj[curr]){
            if(vis[c])continue;
            if(dfs(c,target,vis,adj))return 1;
        }
        return 0;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>>adj(n+1);
        vector<int>vis(n+1,0);
        vector<int>ans;
        for(auto &c:edges){
            vis.assign(n+1,0);

            if(dfs(c[0],c[1],vis,adj)){
                ans=c;
            }

            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }

        return ans;
    }
};

// Time Complexity : O(N^2);
// Space Complexity: O(N);