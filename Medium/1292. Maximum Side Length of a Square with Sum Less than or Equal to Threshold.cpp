// Problem Link: https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/description/?envType=daily-question&envId=2026-01-19

class Solution {
public:
    vector<vector<int>>rsum;

    int check(int x,int y,int n,auto &a,int mx){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=rsum[x+i][y+n]-rsum[x+i][y];
            if(sum>mx)return 0;
        }
        return 1;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n=mat.size(),m=mat[0].size();

        rsum.assign(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cell=mat[i][j];
                rsum[i][j+1]+=rsum[i][j]+cell;
            }
        }

        // for(auto &c:rsum){
        //     for(auto &cc:c)cout<<cc<<" ";
        //     cout<<endl;
        // }

        for(int len=min(n,m);len>0;len--){
            for(int i=0;i+len<=n;i++){
                for(int j=0;j+len<=m;j++){
                    if(check(i,j,len,mat,threshold))return len;
                }
            }
        }

        return 0;
    }
};

// Time Complexity : O(min(N,M)*min(N,M)*N*M) => O(N^4);
// Space Complexity: O(N*M) => O(N^2);