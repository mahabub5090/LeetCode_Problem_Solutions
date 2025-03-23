// Problem Link: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/?envType=daily-question&envId=2025-03-23

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod=1e9+7;
        vector<vector<pair<int,int>>>graph(n);
        for(auto &c:roads){
            graph[c[0]].push_back({c[1],c[2]});
            graph[c[1]].push_back({c[0],c[2]});
        }

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>>pq;

        vector<long long>shortestTime(n,LLONG_MAX);
        vector<int>pathCnt(n,0);
        shortestTime[0]=0;
        pathCnt[0]=1;
        pq.push({0,0});

        while(pq.size()){
            long long time=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            if(time>shortestTime[node])continue;

            for(auto &[nei,roadTime]:graph[node]){
                if(time+roadTime<shortestTime[nei]){
                    shortestTime[nei]=time+roadTime;
                    pathCnt[nei]=pathCnt[node];
                    pq.push({shortestTime[nei],nei});
                }
                else if(time+roadTime==shortestTime[nei]){
                    pathCnt[nei]=(pathCnt[nei]+pathCnt[node])%mod;
                }
            }
        }
        return pathCnt[n-1];
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(N);