// Problem Link: https://leetcode.com/problems/maximal-rectangle/description/?envType=daily-question&envId=2026-01-11

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        if(n==0 || m==0)return 0;

        vector<vector<int>>vc(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vc[i][j]=matrix[i][j]-'0';
            }
        }

        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                if(vc[i][j])vc[i][j]+=vc[i][j-1];
            }
        }

        int ans=0;

        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                int w=vc[i][j];
                if(w==0)continue;

                int curr=w;
                for(int k=i;k<n && vc[k][j];k++){
                    curr=min(curr,vc[k][j]);
                    int h=k-i+1;
                    ans=max(ans,curr*h);
                }
                
                curr=w;
                for(int k=i;k>=0 && vc[k][j];k--){
                    curr=min(curr,vc[k][j]);
                    int h=i-k+1;
                    ans=max(ans,curr*h);
                }
            }
        }
        return ans;
    }
};

// Time Complexity : O(2*N*M) + O(M*N*N) => O(N^3);
// Space Complexity: O(N*M) => O(N^2);