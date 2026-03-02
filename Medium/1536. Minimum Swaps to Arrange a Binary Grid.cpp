// Problem Link: https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/description/?envType=daily-question&envId=2026-03-02

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==0)cnt++;
                else break;
            }
            mp[i]=cnt;
        }

        int ans=0,col=1;
        for(int i=0;i<n;i++){
            if(mp[i]>=n-(i+1))continue;
            else{
                int found=-1;
                for(int j=i;j<n;j++){
                    if(mp[j]>=n-(i+1)){
                        found=j;
                        break;
                    }
                }
                if(found==-1)return -1;

                ans+=found-i;
                for(int j=found;j>i;j--)mp[j]=mp[j-1];
            }
        }
        return ans;
    }
};

// Time Complexity : O(N^2) + O(N^2) => O(N^2);
// Space Complexity: O(N);