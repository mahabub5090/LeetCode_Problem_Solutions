// Problem Link: https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/?envType=daily-question&envId=2024-10-27

#include <vector>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int tt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    int ms=min(n-i,m-j);
                    for(int s=1;s<=ms;s++){
                        int allOnes=1;
                        for(int k=0;k<s;k++){
                            if(matrix[i+s-1][j+k]==0 || matrix[i+k][j+s-1]==0){
                                allOnes=0;
                                break;
                            }
                        }
                        tt+=allOnes;
                        if(allOnes==0)break;
                    }
                }
            }
        }
          return tt;
    }
};

// Time Complexity : O(N*M*(MIN(N,M)^2)) => O(N^4); // Though N<=300,this time complexity got accepted;
// Space Complexity: O(1);


