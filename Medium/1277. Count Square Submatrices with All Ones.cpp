// Problem Link: https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/?envType=daily-question&envId=2024-10-27
// Problem Link: https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/?envType=daily-question&envId=2025-08-20

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

// Way: 2 => (Worst One)

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans=0,m=matrix.size(),n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]){
                    int minS=min(m-i,n-j);
                    int f=1;
                    for(int poss=1;poss<=minS;poss++){
                        int cnt=0;
                        for(int k=i;k<i+poss;k++){
                            for(int l=j;l<j+poss;l++)cnt+=matrix[k][l];
                        }
                        if(cnt!=pow(poss,2)){  
                            ans+=poss-1;
                            break;
                        }
                        if(poss==minS)ans+=minS;
                    }  
                }
            }
        }
        return ans;
    }
};

// Time Complexity : O(N*M*(MIN(N,M)^3)) => O(N^5); // Though N<=300,somehow time complexity got accepted,but is should be got TLE;
// Space Complexity: O(1);
