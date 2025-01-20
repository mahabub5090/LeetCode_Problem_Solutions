// Problem Link: https://leetcode.com/problems/first-completely-painted-row-or-column/description/?envType=daily-question&envId=2025-01-20

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<int>col(n,0),row(m,0);
        map<int,pair<int,int>>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[mat[i][j]]={i,j};
            }
        }
        int cnt=0;
        for(auto &c:arr){
            auto [i,j]=mp[c];
            col[i]++,row[j]++;
            if(col[i]==m || row[j]==n)return cnt;
            cnt++;
        }
        return 0;
    }
};

// Time Complexity : O(N*M) => O(N^2);
// Space Complexity: O(N+M) => O(2*N) => O(N);