// Problem Link: https://leetcode.com/problems/find-closest-node-to-given-two-nodes/description/?envType=daily-question&envId=2025-05-30

class Solution {
public:
    void dfs(int node,auto &edges,auto &dist, auto &vis)
    {
        vis[node]=1;
        int nei=edges[node];
        if(nei!=-1 && vis[nei]==0){
            dist[nei]=dist[node]+1;
            dfs(nei,edges,dist,vis);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int>dist(n,INT_MAX),dist2(n,INT_MAX);
        vector<int>vis(n,0),vis2(n,0);
        dist[node1]=0,dist2[node2]=0;

        dfs(node1,edges,dist,vis);
        dfs(node2,edges,dist2,vis2);

        int ans=-1,minDist=INT_MAX;
        for(int i=0;i<n;i++){
            int currDist=max(dist[i],dist2[i]);
            if(minDist>currDist){
                ans=i;
                minDist=currDist;
            }
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);