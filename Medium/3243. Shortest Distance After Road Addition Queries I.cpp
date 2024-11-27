// Problem Link: https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/description/?envType=daily-question&envId=2024-11-27

class Solution {
public:
    int bfs(int curr,auto &adj,auto &dist){
        queue<int>q;
        q.push(curr);
        while(q.size()){
            int node=q.front();
            q.pop();
            for(auto &c:adj[node]){
                if(dist[node]+1<dist[c]){
                    dist[c]=dist[node]+1;
                    q.push(c);
                }
            }
        }
        return dist.back();
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>adj(n);
        vector<int>dist(adj.size(),0);
        iota(dist.begin(),dist.end(),0);
        vector<int>ans;
        for(int i=0;i<n-1;i++)adj[i].push_back(i+1);
        for(auto &c:queries){
            adj[c[0]].push_back(c[1]);
            ans.push_back(bfs(c[0],adj,dist));
        }
        return ans;
    }
};

// Time Complexity : O(Q*(Q+N)) => O(N^2);
// Space Complextiy: O(Q+N) => O(N);
// Q is the size of given queries array.