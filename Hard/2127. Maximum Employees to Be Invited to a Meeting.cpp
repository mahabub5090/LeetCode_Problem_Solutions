// Problem Link: https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/description/?envType=daily-question&envId=Invalid%20Date

class Solution {
public:
    int bfs(int start,auto &st,auto &vc){
        queue<pair<int,int>>q;
        q.push({start,0});
        int maxDist=0;
        while(q.size()){
            auto [node,dist]=q.front();
            q.pop();
            for(auto &c:vc[node]){ 
                if(st.find(c)!=st.end())continue;
                st.insert(c);
                q.push({c,dist+1});
                maxDist=max(maxDist,dist+1);
            }
        }
        return maxDist;
    }
    int maximumInvitations(vector<int>& favorite) {
        int n=favorite.size();
        vector<vector<int>>invert(n);
        for(int i=0;i<n;i++){
            invert[favorite[i]].push_back(i);
        }
        int longCycle=0,twoCycle=0;
        vector<int>visit(n,0);
        for(int i=0;i<n;i++){
            if(visit[i])continue;
            map<int,int>mp;
            int curr=i,dist=0;
            while(true){
                if(visit[curr])break;
                visit[curr]=1;
                mp[curr]=dist++;
                int nextCurr=favorite[curr];
                if(mp.count(nextCurr)){
                    int len=dist-mp[nextCurr];
                    longCycle=max(longCycle,len);

                    if(len==2){
                        set<int>st;
                        st.insert(curr);
                        st.insert(nextCurr);
                        twoCycle+=2+bfs(curr,st,invert)+bfs(nextCurr,st,invert);
                    }
                    break;
                }
                curr=nextCurr;
            }
        }
        return max(longCycle,twoCycle);
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);