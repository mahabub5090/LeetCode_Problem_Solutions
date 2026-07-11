// Problem Link: https://leetcode.com/problems/count-the-number-of-complete-components/description/?envType=daily-question&envId=2025-03-22
// Problem Link: https://leetcode.com/problems/count-the-number-of-complete-components/description/?envType=daily-question&envId=2026-07-11

class Solution {
public:
    void dfs(int curr, int &compo, int &edges, auto &adj, auto &vis){
        vis[curr]=1;
        compo++;
        edges+=adj[curr].size();
    
        for(auto &c:adj[curr]){
            if(vis[c]) continue;
            dfs(c,compo,edges,adj,vis);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &c:edges){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }

        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]) continue;

            int compo=0, edges=0;
            dfs(i,compo,edges,adj,vis);

            if(compo*(compo-1)==edges) ans++;
        }
        return ans;
    }
};

// Time Complexity : O(E) + O(V) => O(E+V);
// Space Complexity: O(V+E) + O(V) + O(V) => O(V+E);
// E = edges.size(), V = N and 1 <= N <= 50, 0 <= E <= (V*(N-1))/2;