// Problem Link: https://leetcode.com/problems/map-of-highest-peak/description/?envType=daily-question&envId=2025-01-22

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size(),m=isWater[0].size();
        vector<vector<int>>ans(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(q.size()){
            auto [i,j]=q.front();q.pop();
            vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
            for(auto &[l,r]:dir){
                if(i+l>=0 && i+l<n && j+r>=0 && j+r<m && ans[i+l][j+r]==-1){
                    ans[i+l][j+r]=ans[i][j]+1;
                    q.push({i+l,j+r});
                }
            }
        }
        return ans;
    }
};

// Time Complexity : O(N*M) => O(N^2);
// Space Complexity: O(N*M) => O(N^2);