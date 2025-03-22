// Problem Link: https://leetcode.com/problems/count-the-number-of-complete-components/description/?envType=daily-question&envId=2025-03-22

class Solution {
public:
    void dfs(int i,auto &graph,auto &vis,int &comp,int &edges){
        vis[i]=1;
        comp++;
        edges+=graph[i].size();

        for(auto &c:graph[i]){
            if(vis[c]==0)dfs(c,graph,vis,comp,edges);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);
        for(auto &c:edges){
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }
        int ans=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i])continue;

            int edges=0;
            int components=0;
            dfs(i,graph,vis,components,edges);

            if(components*(components-1)==edges)ans++;
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);