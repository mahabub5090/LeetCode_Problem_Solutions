// Problem Link: https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/submissions/1487364351/?envType=daily-question&envId=2024-12-24

class Solution {
private:
    void build(vector<vector<int>>& adj, vector<vector<int>>& edges, int n){
        for(auto &c: edges){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
    }
    void get(auto &p,auto &adj,int node,int dis, auto &vis){
        int d=p.second;
        vis[node]=1;
        if(dis>d){
            p.second=dis;
            p.first=node;
        }
        for(auto &c: adj[node]){
            if(!vis[c]){
                get(p,adj,c,dis+1,vis);
            }
        }
    }
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size()+1;
        int m=edges2.size()+1;
        vector<vector<int>>adj1(n),adj2(m);

        build(adj1,edges1,n);
        build(adj2,edges2,m);

        vector<int>vis(n);
        pair<int,int> p1 ={-1,INT_MIN};
        get(p1,adj1,0,0,vis);

        vis=vector<int>(n,0);
        pair<int,int>p2={-1,INT_MIN};
        get(p2,adj1,p1.first,0,vis);

        int d1=p2.second;

        p1={-1,INT_MIN};
        vis=vector<int>(m,0);
        get(p1,adj2,0,0,vis);
        p2={-1,INT_MIN};
        vis=vector<int>(m,0);
        get(p2,adj2,p1.first,0,vis);

        int d2=p2.second;
        if(edges1.empty())d1=0;
        if(edges2.empty())d2=0;

        return max({d1,d2,(d1+1)/2+(d2+1)/2+1});
    }
};

// Time Complexity : O(N);
// Spcae Complexity: O(N);