// Problem Link: https://leetcode.com/problems/minimum-moves-to-clean-the-classroom/description/?envType=daily-question&envId=2026-09-01

class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    class Data{
        public:
        int i, j, mask, currEnergy, step;
    };


    int minMoves(vector<string>& classroom, int energy) {
        int m=classroom.size(), n=classroom[0].size();

        vector<vector<int>> id(m,vector<int>(n));
        int si, sj, cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(classroom[i][j]=='S') si=i, sj=j;
                else if(classroom[i][j]=='L') id[i][j]=1<<cnt++;
            }
        }

        vector<vector<vector<int>>> best(m, vector<vector<int>>(n, vector<int> (1<<cnt,-1)));
        best[si][sj][0]=energy;

        queue<Data> q;
        q.push({si,sj,0,energy,0});

        while(q.size()){
            Data c=q.front(); q.pop();

            if(c.mask==(1<<cnt)-1) return c.step;
            if(c.currEnergy==0) continue;

            for(int i=0;i<4;i++){
                int ni=c.i + dx[i];
                int nj=c.j + dy[i];

                if(ni<0 || ni>=m || nj<0 || nj>=n || classroom[ni][nj]=='X') continue;

                int newMask=c.mask | id[ni][nj];
                int newEnergy=classroom[ni][nj]=='R'?energy:c.currEnergy-1;

                if(newEnergy>best[ni][nj][newMask]){
                    best[ni][nj][newMask]=newEnergy;
                    q.push({ni,nj,newMask,newEnergy,c.step+1});
                }
            }
        }
        return -1;
    }
};

// Time Complexity : O(M*N) + O(M*N*(2^L)*K) => O(M*N*(2^L)*K);
// Space Complexity: O(M*N*(2^L)*K);