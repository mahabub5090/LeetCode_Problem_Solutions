// Problem Link: https://leetcode.com/problems/find-champion-ii/description/?envType=daily-question&envId=2024-11-26

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>parent(n,-1);
        for(auto &c:edges){
            parent[c[1]]=c[0];
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(parent[i]==-1)ans.push_back(i);
        }
        if(ans.size()!=1)return -1;
        return ans.back();
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(2*N) => O(N);