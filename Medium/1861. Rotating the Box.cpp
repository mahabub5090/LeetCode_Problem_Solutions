// Problem Link: https://leetcode.com/problems/rotating-the-box/submissions/1460746142/?envType=daily-question&envId=2024-11-23
// Problem Link: https://leetcode.com/problems/rotating-the-box/description/?envType=daily-question&envId=2026-05-06


// // class Solution {
// // public:
// //     vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
// //         int n=box.size(),m=box[0].size();
// //         vector<vector<char>>vc(m,vector<char>(n));
// //         int pos=n-1;
// //         for(int i=0;i<n;i++){
// //             for(int j=0;j<m;j++){
// //                 vc[j][pos]=box[i][j];
// //             }
// //             pos--;
// //         }
// //         for(int i=m-1;i>=0;i--){
// //             for(int j=0;j<n;j++){
// //                 if(vc[i][j]=='#'){
// //                     int pos2=i;
// //                     while(pos2+1<m && vc[pos2+1][j]=='.'){
// //                         swap(vc[pos2][j],vc[pos2+1][j]),pos2++;
// //                     }
// //                 }
// //             }
// //         }
// //         return vc;
// //     }
// // };


// // // Time Complexity : O(M*N*M) => O(N^3);
// // // Space Complexity: O(M*N) => O(N^2);

// // Way: 2 =>

// class Solution {
// public:
//     vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
//         int m=boxGrid.size(),n=boxGrid[0].size();
//         vector<vector<int>>cnt(m,vector<int>(n,0));

//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 int val;
//                 if(boxGrid[i][j]=='#') val=1;
//                 else if(boxGrid[i][j]=='*') val=-2;
//                 else val=0;

//                 cnt[i][j]=val;
//                 boxGrid[i][j]='.';
//             }
//             for(int j=1;j<n;j++) {
//                 if(cnt[i][j]==-2 || cnt[i][j-1]==-2) continue;
//                 cnt[i][j]+=cnt[i][j-1];
//             }
//         }


//         for(int i=m-1;i>=0;i--){
//             for(int j=n-1;j>=0;j--){
//                 if(cnt[i][j]==0) boxGrid[i][j]='.';
//                 else if(cnt[i][j]==-2) boxGrid[i][j]='*';
//                 else {
//                     int done=cnt[i][j];
//                     while(j>=0 && cnt[i][j]>0){
//                         if(done-->0) boxGrid[i][j]='#';
//                         j--;
//                     }
//                     j++;
//                 }
//             }
//         }

//         vector<vector<char>>ans(n,vector<char>(m));
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++) ans[j][m-1-i]=boxGrid[i][j];    
//         }
//         return ans;
//     }
// };

// // Time Complexity : O(M*N) + O(M*N) + O(M*N) => O(N^2);
// // Space Complexity: O(M*N) + O(M*N) => O(N^2);

// Way: 3 =>

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m=boxGrid.size(),n=boxGrid[0].size();

        for(int i=m-1;i>=0;i--){
            int empty=n-1;
            for(int j=n-1;j>=0;j--){
                if(boxGrid[i][j]=='*')empty=j-1;
                if(boxGrid[i][j]=='#'){
                    boxGrid[i][j]='.';
                    boxGrid[i][empty]='#';
                    empty--;
                }
            }
        }

        vector<vector<char>>ans(n,vector<char>(m));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) ans[j][m-1-i]=boxGrid[i][j];    
        }
        return ans;
    }
};

// Time Complexity : O(M*N) + O(M*N) => O(N^2);
// Space Complexity: O(M*N) => O(N^2);