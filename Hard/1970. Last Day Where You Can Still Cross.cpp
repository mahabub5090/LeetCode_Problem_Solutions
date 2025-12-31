// Problem Link: https://leetcode.com/problems/last-day-where-you-can-still-cross/description/?envType=daily-question&envId=2025-12-31

class Solution {
public:
    vector<int>dr={1,-1,0,0};
    vector<int>dc={0,0,1,-1};
    vector<int>parent,rank;

    int Find(int id){
        if(parent[id]!=id)parent[id]=Find(parent[id]);
        return parent[id];
    }
    void Union(int a,int b){
        a=Find(a),b=Find(b);
        if(a==b)return;

        if(rank[a]<rank[b])swap(a,b);
        parent[b]=a;
        if(rank[a]==rank[b])rank[a]++;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n=row*col;
        parent.resize(n+2);
        rank.resize(n+2,0);
        vector<vector<int>>grid(row,vector<int>(col,0));
        int top=n,bottom=n+1;

        for(int i=0;i<n+2;i++)parent[i]=i;

        for(int i=n-1;i>=0;i--){
            int r=cells[i][0]-1;
            int c=cells[i][1]-1;
            grid[r][c]=1;
            int id=r*col+c;

            if(r==0)Union(id,top);
            if(r==row-1)Union(id,bottom);

            for(int d=0;d<4;d++){
                int nr=r+dr[d];
                int nc=c+dc[d];

                if(nr>=0 && nr<row && nc>=0 && nc<col && grid[nr][nc]){
                    Union(id,nr*col+nc);
                }
            }

            if(Find(top)==Find(bottom))return i;
        }
        return 0;
    }
};

// Time Complexity : O(R*C) => O(N^2);
// Space Complexity: O(R*C) => O(N^2);