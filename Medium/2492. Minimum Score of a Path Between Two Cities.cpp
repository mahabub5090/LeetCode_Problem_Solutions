// Problem Link: https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/?envType=daily-question&envId=2026-07-04

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto &c:roads){
            int u=c[0], v=c[1], w=c[2];
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }

        vector<int> vis(n+1,0);
        queue<int> q;
        q.push(1);
        vis[1]=1;

        int ans=INT_MAX;
        while(q.size()){
            int u=q.front(); q.pop();

            for(auto &[v,w]:graph[u]){
                ans=min(ans,w);
                if(vis[v]==0) q.push(v);
                vis[v]=1;
            }
        }
        return ans;
    }
};

// Time Complexity : O(E) + O(V+E) => O(V+E);
// Space Complexity: O(V+E) + O(V) + O(V) => O(V+E);