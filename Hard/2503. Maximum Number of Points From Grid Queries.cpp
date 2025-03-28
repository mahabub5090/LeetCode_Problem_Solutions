// Problem Link: https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/description/?envType=daily-question&envId=2025-03-28

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int k=queries.size();
        vector<int>ans(k);
        int m=grid.size(),n=grid[0].size();

        vector<pair<int,int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
        vector<pair<int,int>>sq;
 
        for(int i=0;i<queries.size();i++){
             sq.push_back({queries[i],i});
        }
        sort(sq.begin(),sq.end());

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;

        vector<vector<int>>vis(m,vector<int>(n,0));

        int tt=0;
        pq.push({grid[0][0],{0,0}});
        vis[0][0]=1;

        for(auto &[val,i]:sq){
            while(pq.size() && pq.top().first<val){
                auto [val,pos]=pq.top();pq.pop();
                
                int cr=pos.first,cc=pos.second;
                tt++;

                for(auto &[r,c]:dir){
                    int nr=cr+r,nc=cc+c;

                    if(nr>=0 && nc>=0 && nr<m && nc<n && vis[nr][nc]==0){
                        pq.push({grid[nr][nc],{nr,nc}});
                        vis[nr][nc]=1;
                    }
                }
            }
            ans[i]=tt;
        }
        return ans;
    }    
};

// Time Complexity : O(K∗Log(K)+M∗N∗Log(K)) => O((N^2)logN);
// Space Complexity: O(M∗N+K) => O(N^2);
// m is grid.size(),n=grid[0].size() and k=m*n here;