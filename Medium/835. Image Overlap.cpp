// Problem Link: https://leetcode.com/problems/image-overlap/description/?envType=daily-question&envId=2026-09-13

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size(), ans=0;
        
        for(int x=-n+1;x<n;x++){
            for(int y=-n+1;y<n;y++){
                int cnt=0;
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        if(img1[i][j]==0) continue;

                        int ni=i+x, nj=j+y;
                        if(ni>=0 && ni<n && nj>=0 && nj<n && img2[ni][nj]) cnt++;
                    }
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};

// Time Complexity : O((N*2) * (N*2) * N * N) => O(N^4);
// Space Complexity: O(1);