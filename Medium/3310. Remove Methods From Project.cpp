// Problem Link: https://leetcode.com/problems/remove-methods-from-project/description/?envType=daily-question&envId=2026-08-05

class Solution {
public:
    void dfs(int curr,auto &graph,auto &vis) {
        if(vis[curr]) return;

        vis[curr]++;
        for(auto &c:graph[curr]) dfs(c,graph,vis);
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);
        for(auto &c:invocations) graph[c[0]].push_back(c[1]);

        vector<int> vis(n,0);
        dfs(k,graph,vis);

        for(auto &c:invocations){
            if(vis[c[0]]==0 && vis[c[1]]) {
                vector<int> ans;
                for(int i=0;i<n;i++) ans.push_back(i);
                return ans;
            }
        }

        vector<int> ans;
        for(int i=0;i<n;i++) if (vis[i]!=1) ans.push_back(i);
        return ans;
    }
};

// Time Complexity : O(M) + O(N+M) + O(M+N) + O(N) => O(N+M);
// Space Complexity: O(N+M) + O(N) + O(N) => O(N+M);