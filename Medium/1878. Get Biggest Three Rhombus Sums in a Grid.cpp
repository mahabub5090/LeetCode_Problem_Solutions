// Problem Link: https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/description/?envType=daily-question&envId=2026-03-16

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>pref(m+1,vector<int>(n+2,0)),pref2;
        pref2=pref;

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                pref[i][j]=pref[i-1][j-1]+grid[i-1][j-1];
                pref2[i][j]+=pref2[i-1][j+1]+grid[i-1][j-1];
            }
        }

        set<int,greater<int>>uniqueSums;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                uniqueSums.insert(grid[i][j]);

                for(int len=1;;len++){
                    int top=i,bottom=i+2*len;
                    int l=j-len,r=j+len;

                    if(bottom>=m || l<0 || r>=n)break;
                    
                    int side1=pref2[i+len+1][j-len+1]-pref2[i][j+2];
                    int side2=pref[i+len+1][j+len+1]-pref[i][j];
                    int side3=pref[i+2*len+1][j+1]-pref[i+len][j-len];
                    int side4=pref2[i+2*len+1][j+1]-pref2[i+len][j+len+2];

                    int currSum=side1+side2+side3+side4-(grid[i][j]+grid[i+2*len][j]+grid[i+len][j-len]+grid[i+len][j+len]);

                    uniqueSums.insert(currSum);
                }

                while(uniqueSums.size()>3){
                    uniqueSums.erase(prev(uniqueSums.end()));
                }
            }
        }

        return vector<int>(uniqueSums.begin(),uniqueSums.end());
    }
};

// Time Complexity : O(M*N*min(M,N)) => O(N^3);
// Space Complexity: O(M*N) => O(N^2);