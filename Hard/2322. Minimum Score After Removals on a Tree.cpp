// Problem Link: https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/description/?envType=daily-question&envId=2025-07-24

class Solution {
public:
    vector<vector<int>>e;
    vector<int>xorVal,in,out;
    int t=0,ttXor=0;

    int isAncestor(int u,int v){
        return in[u]<=in[v] && out[v]<=out[u];
    }

    void dfsTime(int u,int p){
        in[u]=++t;
        for(auto &c:e[u]){
            if(c==p)continue;
            dfsTime(c,u);
        }
        out[u]=t;
    }

    int dfs(int u,int p,auto &nums){
        xorVal[u]=nums[u];
        for(auto &c:e[u]){
            if(c==p)continue;
            xorVal[u]^=dfs(c,u,nums);
        }
        return xorVal[u];
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        e.assign(n,{});
        xorVal.assign(n,0);
        in.assign(n,0);
        out.assign(n,0);

        for(auto &c:edges){
            e[c[0]].push_back(c[1]);
            e[c[1]].push_back(c[0]);
        }

        dfs(0,-1,nums);
        ttXor=xorVal[0];
        dfsTime(0,-1);

        int ans=INT_MAX;

        for(int u=1;u<n;u++){
            for(int v=u+1;v<n;v++){
                int a,b,c;
                if(isAncestor(u,v)){
                    a=xorVal[v];
                    b=xorVal[u]^xorVal[v];
                    c=ttXor^xorVal[u];
                }
                else if(isAncestor(v,u)){
                    a=xorVal[u];
                    b=xorVal[v]^xorVal[u];
                    c=ttXor^xorVal[v];
                }
                else{
                    a=xorVal[u];
                    b=xorVal[v];
                    c=ttXor^a^b;
                }

                int maxV=max({a,b,c});
                int minV=min({a,b,c});
                ans=min(ans,maxV-minV);
            }
        }

        return ans;
    }
};

// Time Complexity : O(2*N) + O(N*N) => O(N^2);
// Space Complexity: O(N);