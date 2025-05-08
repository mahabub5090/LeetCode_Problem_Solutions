// Problem Link: https://leetcode.com/problems/find-minimum-time-to-reach-last-room-ii/description/?envType=daily-question&envId=2025-05-08

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size(),m=moveTime[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        vector<vector<int>>vis(n,vector<int>(m,0));

        vector<int>dx={-1,0,1,0};
        vector<int>dy={0,1,0,-1};
        
        priority_queue<tuple<int,int,int,int>,vector<tuple<int,int,int,int>>,greater<>>pq;
        pq.push({0,0,0,0});
        dist[0][0]=0;

        while(pq.size()){
            auto [time,i,j,moveCnt]=pq.top();pq.pop();

            if(vis[i][j])continue;
            vis[i][j]=1;

            if(i==n-1 && j==m-1)return time;

            for(int id=0;id<4;id++){
                int ni=i+dx[id];
                int nj=j+dy[id];

                if(ni<0 || nj<0 || ni>=n || nj>=m)continue;

                
                int step=moveCnt%2?2:1;
                int wait=max(time,moveTime[ni][nj]);
                int nt=wait+step;

                if(nt<dist[ni][nj]){
                    dist[ni][nj]=nt;
                    pq.push({nt,ni,nj,moveCnt+1});
                }
            }
        }
        return -1;
    }
};

// Time Complexity : O(N*M*log(M*N)) => O((N^2)log(N^2));
// Space Complexity: O(N*M) => O(N^2);