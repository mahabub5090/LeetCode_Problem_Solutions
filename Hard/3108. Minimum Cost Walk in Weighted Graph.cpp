// Problem Link: https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/description/?envType=daily-question&envId=2025-03-20

class Solution {
public:
    vector<int>parent,depth;
    int find(int node){
        if(parent[node]==-1)return node;
        return parent[node]=find(parent[node]);
    }

    void Union(int node,int node2){
        int root=find(node);
        int root2=find(node2);

        if(root==root2)return;

        if(depth[root]<depth[root2])swap(root,root2);
        parent[root2]=root;
        if(depth[root]==depth[root2])depth[root]++;
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n,-1);
        depth.resize(n,0);

        vector<int>cc(n,-1),ans;
        
        for(auto &c:edges)Union(c[0],c[1]);
        for(auto &c:edges){
            int root=find(c[0]);
            cc[root]&=c[2];
        }

        for(auto &c:query){
            int s=c[0],e=c[1];

            if(find(s)!=find(e))ans.push_back(-1);
            else{
                int root=find(s);
                ans.push_back(cc[root]);
            }
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Time Complexity : O(N);
    