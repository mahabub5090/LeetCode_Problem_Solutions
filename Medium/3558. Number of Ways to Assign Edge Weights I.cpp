// Problem Link: https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-i/description/?envType=daily-question&envId=2026-06-11

class Solution {
public:
    int dfs(auto &g,int x,int f){
        int maxDept=0;
        for(auto &c:g[x]){
            if(c==f) continue;
            maxDept=max(maxDept,dfs(g,c,x)+1);
        }
        return maxDept;
    }
    int quickPow(int x,int y){
        int tt=1, mod=1e9+7;
        while(y){
            if(y&1) tt=(1ll*tt*x)%mod;
            x=(1ll*x*x)%mod;
            y>>=1;
        }
        return tt;
    }


    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>> graph(n+1);

        for(auto &c:edges){
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }

        int maxDept=dfs(graph,1,0);
        return (int)quickPow(2,maxDept-1);
    }
};

// Time complexity : O(N) + O(N) + O(logN) => O(N);
// Space Complexity: O(N) + O(N) => O(N); // for graph vector and recursion stack; 