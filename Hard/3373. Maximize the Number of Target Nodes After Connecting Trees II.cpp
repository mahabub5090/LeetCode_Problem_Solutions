// Problem Link: https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/description/?envType=daily-question&envId=2025-05-29

class Solution {
public:
    int dfs(int node,int parent,int depth,auto &child,auto &color){
        int ans=1-depth%2;
        color[node]=depth%2;
        for(auto &c:child[node]){
            if(c==parent)continue;
            ans+=dfs(c,node,depth+1,child,color);
        }
        return ans;
    }
    vector<int>build(auto &edges,auto &color){
        int n=edges.size()+1;
        vector<vector<int>>child(n);
        for(auto &c:edges){
            child[c[0]].push_back(c[1]);
            child[c[1]].push_back(c[0]);
        }
        int ans=dfs(0,-1,0,child,color);
        return {ans,n-ans};
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size()+1,m=edges2.size()+1;
        vector<int>color(n),color2(m);
        vector<int>cnt=build(edges1,color);
        vector<int>cnt2=build(edges2,color2);
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=cnt[color[i]]+max(cnt2[0],cnt2[1]);
        }
        return ans;
    }
};

// Time Complexity : O(N+M) => O(N);
// Space Complexity: O(N+M) => O(N);