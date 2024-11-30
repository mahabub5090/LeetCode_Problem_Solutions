// Problem Link: https://leetcode.com/problems/valid-arrangement-of-pairs/description/?envType=daily-question&envId=2024-11-30

class Solution {
public:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> deg;
    void build_graph(vector<vector<int>>& pairs){
        for(auto& edge: pairs){
            int start=edge[0], end=edge[1];
            adj[start].push_back(end);
            deg[start]++;
            deg[end]--;
        }
    }

    vector<int> rpath;
    void euler(int i){
        vector<int> stk={i};
        while(!stk.empty()){
            i = stk.back();
            if(adj[i].empty()){
                rpath.push_back(i);
                stk.pop_back();
            } 
            else {
                int j=adj[i].back();
                adj[i].pop_back();
                stk.push_back(j);
            }
        }
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        const int e = pairs.size();
        adj.reserve(e);
        deg.reserve(e);
    
        build_graph(pairs);

        int i0=deg.begin()->first;
        for (auto &[v, d]: deg){
            if (d == 1){
                i0=v;
                break;
            } 
        }

        euler(i0);

        vector<vector<int>> ans;
        ans.reserve(e);

        for (int i=rpath.size()-2; i>=0; i--) 
            ans.push_back({rpath[i+1], rpath[i]});
        return ans;
    }
};

// Time Complexity : O(E) => O(N);
// Space Complexity: O(E) => O(N);
// Hierholzer’s algorithm 
