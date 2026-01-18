// Problem Link: https://leetcode.com/problems/largest-magic-square/description/?envType=daily-question&envId=2026-01-18

class Solution {
public:
    vector<vector<int>>rsum,csum;

    int check(int x,int y,int n,auto &a){
        int tt=rsum[x][y+n]-rsum[x][y];

        for(int i=0;i<n;i++){  
            int sum=rsum[x+i][y+n]-rsum[x+i][y];
            int sum2=csum[y+i][x+n]-csum[y+i][x];

            if(sum!=tt || sum2!=tt)return 0;
        }

        int sum=0,sum2=0;
        for(int i=0;i<n;i++){
            sum+=a[x+i][y+i];
            sum2+=a[x+n-i-1][y+i];
        }

        return sum==tt && sum2==tt;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();

        rsum.resize(n,vector<int>(m+1,0));
        csum.resize(m,vector<int>(n+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cell=grid[i][j];

                rsum[i][j+1]+=rsum[i][j]+cell;
                csum[j][i+1]+=csum[j][i]+cell;
            }
        }

        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int limit=min(n-i,m-j);
                for(int k=limit;k>1;k--){
                    if(check(i,j,k,grid)){
                        ans=max(ans,k);
                        break;
                    }
                }
            }
        }

        return ans;
    }
};

// Time Complexity : O(N*M) + O(N*M*min(N,M)*min(N,M)) => O(N^2);
// Space Complexity: O(N*M) + O(M*N) => O(N^2);