// Problem Link: https://leetcode.com/problems/find-minimum-time-to-reach-last-room-i/description/?envType=daily-question&envId=2025-05-07

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size(),m=moveTime[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<>>pq;

        vector<int>dx={-1,0,1,0};
        vector<int>dy={0,1,0,-1};

        dist[0][0]=0;
        pq.push({0,{0,0}});

        while(pq.size()){
            auto [time,pos]=pq.top();pq.pop();
            auto [i,j]=pos;

            if(i==n-1 && j==m-1)return time;

            if(time>dist[i][j])continue;

            for(int id=0;id<4;id++){
                int ni=i+dx[id];
                int nj=j+dy[id];
                if(ni>=0 && ni<n && nj>=0 && nj<m){
                    int wait=max(time, moveTime[ni][nj]);
                    int nt=wait+1;
                    if(nt<dist[ni][nj]){
                        dist[ni][nj]=nt;
                        pq.push({nt,{ni,nj}});
                    }
                }
            }
        }
        return -1;
    }
};

// Time Complexity : O(N*M*log(M*N)) => O((N^2)log(N^2));
// Space Complexity: O(N*M) => O(N^2);