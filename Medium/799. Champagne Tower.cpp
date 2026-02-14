// Problem Link: https://leetcode.com/problems/champagne-tower/description/?envType=daily-question&envId=2026-02-14

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>pre(101,vector<double>(101,0));
        pre[0][0]=1.0*poured;

        for(int r=0;r<=query_row;r++){
            for(int c=0;c<=r;c++){
                double quantity=(pre[r][c]-1)/2.0;

                if(quantity>0){
                    pre[r+1][c]+=quantity;
                    pre[r+1][c+1]+=quantity;
                }
            }
        }
        return min(1.0,pre[query_row][query_glass]);
    }
};

// Time Complexity : O(r*c) => O(N^2);
// Space Complexity: O(101*101) => O(10201) => O(1);
// here r is row and c is column and both < 100;