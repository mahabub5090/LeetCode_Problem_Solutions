// Problem Link: https://leetcode.com/problems/find-the-safest-path-in-a-grid/description/?envType=daily-question&envId=2026-07-01

class Solution {
public:
    vector<int> row = {0,0,-1,1};
    vector<int> col = {-1,1,0,0};

    void bfs(vector<vector<int>>& grid,vector<vector<int>>& score,int n) {
        queue<pair<int, int>>Q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++){
                if(grid[i][j]) {
                    score[i][j] = 0;
                   Q.push({i, j});
                }
            }
        }

        while(!Q.empty()){
            auto t = Q.front();
            Q.pop();

            int x = t.first, y = t.second;
            int s = score[x][y];

            for(int i =0; i < 4; i++){
                int newX = x + row[i];
                int newY = y + col[i];

                if(newX >= 0 && newX < n && newY >= 0 && newY < n && score[newX][newY] > 1 + s) { 

                    score[newX][newY] = 1 + s;
                    Q.push({newX, newY});
                }
            }
        }
    }


    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n - 1][n - 1]) return 0;

        vector<vector<int>> score(n,vector<int>(n,INT_MAX));
        bfs(grid, score, n);
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({score[0][0], {0,0}});

        while(!pq .empty()){
            auto temp = pq.top().second;
            auto safe = pq.top().first;
            pq.pop();

            if(temp.first == n - 1 && temp.second == n - 1) return safe;
            vis[temp.first][temp.second] = true;

            for(int i = 0; i < 4; i++) {
                int newX = temp.first + row[i];
                int newY = temp.second + col[i];

                if(newX >= 0 && newX < n && newY >= 0 && newY < n && !vis[newX][newY]){
                    int s = min(safe, score[newX][newY]);
                    pq.push({s, {newX, newY}});
                    vis[newX][newY] = true;
                }
            }
        }

        return 0;
    }
};

// Time Complexity : O(N*N) + O(4*N*N*log(N*N)) => O((N^2)logN);
// Space Complexity: O(N*N) + O(N*N) + O(N*N) + O(N*N) => O(N^2);