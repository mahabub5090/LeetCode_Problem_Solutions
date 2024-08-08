// Problem Link: https://leetcode.com/problems/spiral-matrix-iii/description/?envType=daily-question&envId=2024-08-08

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>>ans;
        ans.push_back({rStart,cStart});
        int step=1,cnt=1,di=0;
        int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        while(cnt!=(rows*cols)){
            for(int i=0;i<2;i++){
                for(int j=0;j<step;j++){
                    rStart+=dir[di][0],cStart+=dir[di][1];
                    if(0<=rStart && rStart<rows && 0<=cStart && cStart<cols)
                    cnt++,ans.push_back({rStart,cStart});
                }
                di+=1;
                di%=4;
            }
            step++;
        }
        return ans;
    }
};

// Time Complexity : O(rows*cols) => O(N^2);
// Space Complexity: O(rows*cols) => O(N^2);