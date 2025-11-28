// Problem Link: https://leetcode.com/problems/maximum-number-of-k-divisible-components/description/?envType=daily-question&envId=2024-12-21
// Problem Link: https://leetcode.com/problems/maximum-number-of-k-divisible-components/description/?envType=daily-question&envId=2025-11-28

class Solution {
public:
    int ans=0;
    unordered_map<int,vector<int>>adj;
    long long dfs(int node,int parent,int &k,auto &values){
        long long subTreeSum=values[node];
        for(auto &c:adj[node]){
            if(c!=parent){
                subTreeSum+=dfs(c,node,k,values);
            }
        }
        if(subTreeSum%k==0)ans++,subTreeSum=0;
        return subTreeSum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        for(auto &c:edges){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        dfs(0,-1,k,values);
        return ans;
    }
};


// Time Complexity : O(N);
// Space Complexity: O(N);