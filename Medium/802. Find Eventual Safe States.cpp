// Problem Link: https://leetcode.com/problems/find-eventual-safe-states/description/?envType=daily-question&envId=2025-01-24

class Solution {
public:
    unordered_map<int,int>mp;
    int dfs(int i,auto &vc){
        if(mp.count(i))return mp[i];
        mp[i]=0;
        for(auto &c:vc[i]){
            if(dfs(c,vc)==0)return 0;
        }
        return mp[i]=1;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(dfs(i,graph))ans.push_back(i);
        }
        return ans;
    }
};

// Time Complexity : O(E+V) => O(N);
// Space Complexity: O(V) => O(N);
// E is edges and V is nodes;