// Problem Link: https://leetcode.com/problems/network-recovery-pathways/description/?envType=daily-question&envId=2026-07-03

class Solution {
public:
    using ll = long long;

    int check(int mid, auto &graph, ll k){
        int n=graph.size();
        vector<ll> dis(n,LLONG_MAX);
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>> pq;

        dis[0]=0;
        pq.push({0,0});

        while(pq.size()){
            auto [d,u]=pq.top();
            pq.pop();

            if(d>k) return 0;
            if(u==n-1) return 1;
            if(d>dis[u]) continue;

            for(auto &[v,w]:graph[u]){
                if(w<mid) continue;

                if(dis[v]>dis[u]+w){
                    dis[v]=dis[u]+w;
                    pq.push({dis[v],v});
                }
            }
        }

        return 0;
    }


    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();
        vector<vector<pair<int,int>>> graph(n);
        int l=INT_MAX, r=0;

        for(auto &c:edges){
            int u=c[0], v=c[1], w=c[2];

            if(online[u]==0 || online[v]==0) continue;

            graph[u].push_back({v,w});
            l=min(l,w);
            r=max(r,w);
        }

        if(check(l,graph,k)==0) return -1;

        while(l<=r){
            int mid=l+(r-l)/2;
            
            if(check(mid,graph,k)) l=mid+1;
            else r=mid-1;
        }
        return r;
    }
};

// Time Complexity : O(E) + O(ElogV) + O(log(W) * ElogV) => O(E*(logV)*(logW)) ;
// Space Complexity: O(V+E) + O(V) + O(E) => O(V+E);