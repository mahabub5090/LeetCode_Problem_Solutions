// Problem Link: https://leetcode.com/problems/snakes-and-ladders/description/?envType=daily-question&envId=2025-05-31

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size(),label=1;
        vector<pair<int,int>>cells(n*n+1);
        vector<int>cols(n);
        iota(cols.begin(),cols.end(),0);

        for(int r=n-1;r>=0;r--) {
            for(int c:cols) {
                cells[label++]={r,c};
            }
            reverse(cols.begin(),cols.end());  
        }

        vector<int>dist(n*n+1,-1);
        dist[1]=0;
        queue<int>q;
        q.push(1);

        while(q.size()) {
            int curr=q.front();q.pop();
            for(int i=1;i<=6 && curr+i<=n*n;i++) {
                auto [r,c]=cells[curr+i];
                int dest=board[r][c]==-1?curr+i:board[r][c];
                if(dist[dest]==-1) {
                    dist[dest]=dist[curr]+1;
                    q.push(dest);
                }
            }
        }
        return dist[n*n];
    }
};

// Time Complexity : O(N^2);
// Space Complexity: O(N^2);