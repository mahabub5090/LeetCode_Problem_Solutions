// Problem Link: https://leetcode.com/problems/most-profitable-path-in-a-tree/description/?envType=daily-question&envId=2025-02-24

class Solution {
public:
    int getAns(int src,int parent,int time,int bob,auto &amount,auto &vc,auto &dist){
        int n=amount.size();
        int mx=0,mxc=INT_MIN;
        if(src==bob)dist[src]=0;
        else dist[src]=n;

        for(auto &c:vc[src]){
            if(c!=parent){
                mxc=max(mxc,getAns(c,src,time+1,bob,amount,vc,dist));
                dist[src]=min(dist[src],dist[c]+1);
            }
        }

        if(dist[src]>time)mx+=amount[src];
        else if(dist[src]==time)mx+=amount[src]/2;
        
        if(mxc==INT_MIN)return mx;
        return mx+mxc;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=amount.size();
        vector<vector<int>>vc(n);
        vector<int>dist(n,INT_MAX);
        
        for(auto &c:edges){
            vc[c[0]].push_back(c[1]);
            vc[c[1]].push_back(c[0]);
        }
        return getAns(0,-1,0,bob,amount,vc,dist);
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);