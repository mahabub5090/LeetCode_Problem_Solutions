// Problem Link: https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/description/?envType=daily-question&envId=2026-01-27

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &c:edges){
            adj[c[0]].push_back({c[1],c[2]});
            adj[c[1]].push_back({c[0],2*c[2]});
        }

        vector<int>vis(n,0),dist(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int, int>>>pq;

        pq.push({0,0});
        dist[0]=0;

        while(pq.size()){
            auto [d,next]=pq.top();
            pq.pop();

            if(next==n-1)return dist[next];

            if(d>dist[next] || vis[next])continue;
            vis[next]=1;

            for(auto &[e,w]:adj[next]){
                if(dist[next]+w<dist[e]){
                    dist[e]=dist[next]+w;
                    pq.push({dist[e],e});
                }
            }

        }
        return -1;
    }
};

// Time Complexity : O(E) + O(ElogV) => O(NlogN);
// Space Complexity: O(V+E) => O(N);