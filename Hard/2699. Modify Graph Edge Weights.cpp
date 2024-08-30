// Problem Link: https://leetcode.com/problems/modify-graph-edge-weights/submissions/1373430291/?envType=daily-question&envId=2024-08-30

class Solution {
public:
    int dijkstra(int n,int src,int des,vector<pair<int,int>>adj[]){
        vector<int>dist(n,2e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,src});
        dist[src]=0;
        while(pq.size()){
            auto c=pq.top();
            pq.pop();
            int w=c.first,node=c.second;
            for(auto &child:adj[node]){
                int cw=child.second;
                int cn=child.first;
                
                if(dist[cn]>dist[node]+cw){
                    dist[cn]=dist[node]+cw;
                    pq.push({dist[cn],cn});
                }
            }
        }
        return dist[des];
    }

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<pair<int,int>>adj[n];
        for(auto &c:edges){
            if(c[2]!=-1){
                adj[c[0]].push_back({c[1],c[2]});
                adj[c[1]].push_back({c[0],c[2]});
            }
        }
        int dist=dijkstra(n,source,destination,adj);
        if(dist<target)return {};

        bool path=dist==target;

        for(auto &c:edges){
            if(c[2]!=-1)continue;
            
            c[2]=path?2e9:1;

            adj[c[0]].push_back({c[1],c[2]});
            adj[c[1]].push_back({c[0],c[2]});

            if(path==0){
                int newDist=dijkstra(n,source,destination,adj);
                if(newDist<=target){
                    path=1;
                    c[2]+=(target-newDist);
                }
            }
        }

        if(path)return edges;
        return {};
    }
};

// Time Complexity : O((V+E)*logV) => O(NlogN); 
// Space Complexity: O(V+E) => O(N);
// V= number of nodes, E= number of edges;