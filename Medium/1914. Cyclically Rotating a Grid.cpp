// Problem Link: https://leetcode.com/problems/cyclically-rotating-a-grid/description/?envType=daily-question&envId=2026-05-09

// class Solution {
// public:
//     vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
//         int m=grid.size(), n=grid[0].size();

//         int u=0,d=m-1,l=0,r=n-1;
//         while(l<r && u<d){
//             int rotate=k;
//             int totalElement=2*(d-u+r-l);
//             if(totalElement)rotate%=totalElement;

//             while(rotate--){
//                 for(int i=l;i<r;i++) swap(grid[u][i],grid[u][i+1]);
//                 for(int i=u;i<d;i++) swap(grid[i][r],grid[i+1][r]);
//                 for(int i=r;i>l;i--) swap(grid[d][i],grid[d][i-1]);
//                 for(int i=d;i>u+1;i--) swap(grid[i][l],grid[i-1][l]);
//             }
//             l++,u++,r--,d--;
//         }
//         return grid;
//     }
// };

// // Time Complexity : O(min(M,N)/2) * O(K') * O(2*(M+N)) => O(N^3);
// // Space Complexity: O(1);
// // K' <= O(2*(M+N-2));


// Way: 2 =>

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(), n=grid[0].size();

        int u=0,d=m-1,l=0,r=n-1;
        while(l<r && u<d){
            vector<int> layer;
            for(int i=l;i<r;i++) layer.push_back(grid[u][i]);
            for(int i=u;i<d;i++) layer.push_back(grid[i][r]);
            for(int i=r;i>l;i--) layer.push_back(grid[d][i]);
            for(int i=d;i>u;i--) layer.push_back(grid[i][l]);

            int len=layer.size(), rotation=k%len;
            rotate(layer.begin(), layer.begin()+rotation, layer.end());

            int idx=0;
            for(int i=l;i<r;i++) grid[u][i]=layer[idx++];
            for(int i=u;i<d;i++) grid[i][r]=layer[idx++];
            for(int i=r;i>l;i--) grid[d][i]=layer[idx++];
            for(int i=d;i>u;i--) grid[i][l]=layer[idx++];

            l++,u++,r--,d--;
        }
        return grid;
    }
};

// Time Complexity : O(M*N) + O(M*N) + O(M*N) => O(N^2);
// Space Complexity: O(2*(M+N-2)) => O(N);