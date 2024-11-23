// Problem Link: https://leetcode.com/problems/rotating-the-box/submissions/1460746142/?envType=daily-question&envId=2024-11-23

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n=box.size(),m=box[0].size();
        vector<vector<char>>vc(m,vector<char>(n,'a'));
        int pos=n-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vc[j][pos]=box[i][j];
            }
            pos--;
        }
        for(int i=m-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(vc[i][j]=='#'){
                    int pos2=i;
                    while(pos2+1<m && vc[pos2+1][j]=='.'){
                        swap(vc[pos2][j],vc[pos2+1][j]),pos2++;
                    }
                }
            }
        }
        return vc;
    }
};

// Time Complexity : O(M*N) => O(N^2);
// Space Complexity: O(M*N) => O(N^2);