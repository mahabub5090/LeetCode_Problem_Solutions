// Problem Link: https://leetcode.com/problems/find-all-people-with-secret/description/?envType=daily-question&envId=2025-12-19

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_map<int,vector<pair<int,int>>>graph;
        for(auto &c:meetings){
            int x=c[0],y=c[1],t=c[2];
            graph[x].push_back({t,y});
            graph[y].push_back({t,x});
        }

        vector<int>fast(n,INT_MAX);
        fast[0]=0;
        fast[firstPerson]=0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        pq.push({0,firstPerson});

        vector<int>vis(n,0);

        while(pq.size()){
            auto [time,p]=pq.top();pq.pop();

            if(vis[p])continue;
            vis[p]++;

            for(auto [t,nextP]:graph[p]){
                if(vis[nextP]==0 && t>=time){
                    fast[nextP]=t;
                    pq.push({t,nextP});
                }
            }
        }

        vector<int>ans;
        for(int i=0;i<n;i++){
            if(vis[i])ans.push_back(i);
        }
        return ans;
    }
};

// Time Complexity : O(M * logN) => O(NlogN);
// Space Complexity: O(N) + O(M) => O(N);
// Here M is meetings.size();