// Problem Link: https://leetcode.com/problems/largest-color-value-in-a-directed-graph/description/?envType=daily-question&envId=2025-05-26

class Solution {
public:
    int dfs(int node,string &colors,auto &adj,auto &cnt,auto &vis){
        if(vis[node]==0){
            vis[node]=1;
            for(auto &c:adj[node]){
                if(dfs(c,colors,adj,cnt,vis)==INT_MAX){
                    return INT_MAX;
                }
                for(int i=0;i<26;i++){
                    cnt[node][i]=max(cnt[node][i],cnt[c][i]);
                }
            }
            cnt[node][colors[node]-'a']++;
            vis[node]=2;
        }
        return vis[node]==2?cnt[node][colors[node]-'a']:INT_MAX;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<vector<int>>adj(n),cnt(n,vector<int>(26,0));
        vector<int>vis(n,0);
        for(auto &c:edges)adj[c[0]].push_back(c[1]);
        int ans=0;
        for(int i=0;i<n && ans!=INT_MAX;i++){
            ans=max(ans,dfs(i,colors,adj,cnt,vis));
        }
        return ans==INT_MAX?-1:ans;
    }
};

// Time Complexity : O(V+26*E) => O(N);
// Space Complexity: O(V*26+E) => O(N);