// Problem Link: https://leetcode.com/problems/count-unguarded-cells-in-the-grid/description/?envType=daily-question&envId=2024-11-21
// Problem Link: https://leetcode.com/problems/count-unguarded-cells-in-the-grid/description/?envType=daily-question&envId=2025-11-02

// class Solution {
// public:
//     void occupied(int i,int j,auto &vc){
//         int n=vc.size(),m=vc[0].size();
//         vector<int>c={i,j};
//         while(j+1<m && vc[i][j+1]!=-1 && vc[i][j+1]!=1)vc[i][j+1]=2,j++;
//         i=c[0],j=c[1];
//         while(i+1<n && vc[i+1][j]!=-1 && vc[i+1][j]!=1)vc[i+1][j]=2,i++;
//         i=c[0],j=c[1];
//         while(j-1>=0 && vc[i][j-1]!=-1 && vc[i][j-1]!=1)vc[i][j-1]=2,j--;
//         i=c[0],j=c[1];
//         while(i-1>=0 && vc[i-1][j]!=-1 && vc[i-1][j]!=1)vc[i-1][j]=2,i--;
//     }
//     int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
//         vector<vector<int>>vc(m,vector<int>(n,0));
//         for(auto &c:walls){
//             vc[c[0]][c[1]]=-1;
//         }
//         for(auto &c:guards){
//             vc[c[0]][c[1]]=1;
//         }
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(vc[i][j]==1)occupied(i,j,vc);
//             }
//         }
//         int cnt=0;
//         for(auto &c:vc){
//             for(auto &cc:c)if(cc==0)cnt++;
//             for(auto &cc:c)cout<<cc<<" ";
//             cout<<endl;
//         }
//         return cnt;
//     }
// };

// // Time Complexity : O(M*N) => O(N^2);
// // Space Complexity: O(M*N) => O(N^2);

// Way: 2 =>

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(auto &c:walls)vis[c[0]][c[1]]=2;
        for(auto &c:guards)vis[c[0]][c[1]]=3;
        
        for(auto &c:guards){
            int x=c[0],y=c[1];
            for(int i=x-1;i>=0;i--){
                if(vis[i][y]>1)break;
                vis[i][y]=1;
            }
            for(int i=x+1;i<m;i++){
                if(vis[i][y]>1)break;
                vis[i][y]=1;
            }
            for(int j=y-1;j>=0;j--){
                if(vis[x][j]>1)break;
                vis[x][j]=1;
            }
            for(int j=y+1;j<n;j++){
                if(vis[x][j]>1)break;
                vis[x][j]=1;
            }
        }

        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0)cnt++;
            }
        }
        return cnt;
    }
};

// Time Complexity : O(4*M*N) => O(N^2);
// Space Complexity: O(M*N) => O(N^2);