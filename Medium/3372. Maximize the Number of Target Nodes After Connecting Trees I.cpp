// Problem Link: https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/description/?envType=daily-question&envId=2025-05-28

class Solution {
public:
    int dfs(int node,int parent,auto &child,int k){
        if(k<0)return 0;
        int ans=1;
        for(auto &c:child[node]){
            if(c==parent)continue;
            ans+=dfs(c,node,child,k-1);
        }
        return ans;
    }
    vector<int> build(auto &edges,int k){
        int n=edges.size()+1;
        vector<vector<int>>child(n);
        for(auto &c:edges){
            child[c[0]].push_back(c[1]);  
            child[c[1]].push_back(c[0]);  
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=dfs(i,-1,child,k);
        }
        return ans;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n=edges1.size()+1;
        vector<int>cnt=build(edges1,k);
        vector<int>cnt2=build(edges2,k-1);
        int maxCnt2=*max_element(cnt2.begin(),cnt2.end());      
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=cnt[i]+maxCnt2;
        }
        return ans;
    }
};

// Time Complexity : O(N^2)+O(M^2)) => O(N^2);
// Space Complexity: O(N)+O(M) => O(N);