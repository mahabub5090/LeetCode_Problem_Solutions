// Problem Link: https://leetcode.com/problems/magic-squares-in-grid/description/?envType=daily-question&envId=2024-08-09

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if(grid.size()<3 || grid[0].size()<3)return 0;
        int ans=0;
        for(int i=0;i+2<grid.size();i++)
        {
            int ii=0;
            while(ii+2<grid[0].size()){
                bool ok=1;
                set<int>st;int mx=0;
                for(int j=0;j<3;j++){
                    int sum=0,sum2=0;;
                    for(int k=0;k<3;k++){
                        sum+=grid[i+j][ii+k];
                        sum2+=grid[i+k][ii+j];
                        st.insert(grid[i+j][ii+k]);
                        st.insert(grid[i+k][ii+j]);
                        if(grid[i+j][ii+k]>9)ok=0;
                    }
                    if(sum!=sum2 || sum!=15)ok=0;
                }
                int a=grid[i][ii]+grid[i+1][ii+1]+grid[i+2][ii+2];
                int b=grid[i+2][ii]+grid[i+1][ii+1]+grid[i][ii+2];
                if(ok && a==b && a==15 && st.size()==9)ans++;
                ii++;
            }
        }
        return ans;
    }
};

// Time Complexity : O(r*c*(3^2)) => O(N^2); // r=rows,c=cols;(in Grid);
// Space Complexity: O(1*4)+O(9) => O(1);