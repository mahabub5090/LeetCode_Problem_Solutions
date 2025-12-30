// Problem Link: https://leetcode.com/problems/magic-squares-in-grid/description/?envType=daily-question&envId=2024-08-09
// Problem Link: https://leetcode.com/problems/magic-squares-in-grid/description/?envType=daily-question&envId=2025-12-30

// class Solution {
// public:
//     int numMagicSquaresInside(vector<vector<int>>& grid) {
//         if(grid.size()<3 || grid[0].size()<3)return 0;
//         int ans=0;
//         for(int i=0;i+2<grid.size();i++)
//         {
//             int ii=0;
//             while(ii+2<grid[0].size()){
//                 bool ok=1;
//                 set<int>st;int mx=0;
//                 for(int j=0;j<3;j++){
//                     int sum=0,sum2=0;;
//                     for(int k=0;k<3;k++){
//                         sum+=grid[i+j][ii+k];
//                         sum2+=grid[i+k][ii+j];
//                         st.insert(grid[i+j][ii+k]);
//                         st.insert(grid[i+k][ii+j]);
//                         if(grid[i+j][ii+k]>9)ok=0;
//                     }
//                     if(sum!=sum2 || sum!=15)ok=0;
//                 }
//                 int a=grid[i][ii]+grid[i+1][ii+1]+grid[i+2][ii+2];
//                 int b=grid[i+2][ii]+grid[i+1][ii+1]+grid[i][ii+2];
//                 if(ok && a==b && a==15 && st.size()==9)ans++;
//                 ii++;
//             }
//         }
//         return ans;
//     }
// };

// // Time Complexity : O(r*c*(3^2)) => O(N^2); // r=rows,c=cols;(in Grid);
// // Space Complexity: O(1*4)+O(9) => O(1);

// Way: 2 =>

class Solution {
public:
    int check(int n,int m,auto &grid){
        if(n+3>grid.size() || m+3>grid[0].size())return 0;

        set<int>num,cnt;
        int sum=0,sum2=0;
    
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                sum+=grid[n+i][m+j];
                sum2+=grid[n+j][m+i];
                num.insert(grid[n+i][m+j]);
            }
            cnt.insert(sum);
            cnt.insert(sum2);

            sum=0,sum2=0;
        }

        sum=0,sum2=0;

        sum+=grid[n][m];
        sum+=grid[n+1][m+1];
        sum+=grid[n+2][m+2];

        sum2+=grid[n+2][m];
        sum2+=grid[n+1][m+1];
        sum2+=grid[n][m+2];

        cnt.insert(sum);
        cnt.insert(sum2);

        return cnt.size()==1 && num.size()==9 && *num.rbegin()==9;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=0;

        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
                ans+=check(i,j,grid);
            }
        }
        return ans;
    }
};

// Time Complexity : O(N*M*(3^2)) => O(N^2);
// Space Complexity: O(3^2) => O(1);