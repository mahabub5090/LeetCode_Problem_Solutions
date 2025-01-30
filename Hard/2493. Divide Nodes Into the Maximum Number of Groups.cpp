// Problem Link: https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups/description/?envType=daily-question&envId=2025-01-30

class Solution {
public:
    vector<int> getCC(int i,auto &vis,auto &adj){
        vis[i]=1;
        vector<int>ans;
        ans.push_back(i);
        queue<int>q;
        q.push(i);
        while(q.size()){
            int node=q.front();
            q.pop();
            for(auto &c:adj[node]){
                if(vis[c])continue;
                vis[c]++;
                q.push(c);
                ans.push_back(c);
            }
        }
        return ans;
    }

    int bfs(int i,auto &adj){
        unordered_map<int,int>mp;
        mp[i]=1;
        queue<pair<int,int>>q;
        q.push({i,1});
        int level=0;
        while(q.size()){
            auto [node,dist]=q.front();
            q.pop();
            level=dist;
            for(auto &c:adj[node]){
                if(mp[c] && (mp[c]-dist)%2==0)return 0;
                if(!mp[c]){
                    mp[c]=dist+1;
                    q.push({c,dist+1});
                }
            }
        }
        return level;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n+1);
        for(auto &c:edges){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        
        int ans=0;
        vector<int>vis(n+1,0);

        for(int i=1;i<=n;i++){
            if(vis[i])continue;
            vector<int>cc=getCC(i,vis,adj);
            int maxLevel=0;
            for(auto &c:cc){
                int level=bfs(c,adj);
                if(!level)return -1;
                maxLevel=max(maxLevel,level);
            }
            ans+=maxLevel;
        }
        return ans;
    }
};

// Time Complexity : O(V^2) + O(V*E) => O(N^2);
// Space Complexity: O(V+E) => O(N);