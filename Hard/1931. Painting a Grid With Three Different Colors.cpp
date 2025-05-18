// Problem Link: https://leetcode.com/problems/painting-a-grid-with-three-different-colors/description/?envType=daily-question&envId=2025-05-18

class Solution {
public:
    int colorTheGrid(int m, int n) {
        int mod=1e9+7;
        unordered_map<int,vector<int>>valid;
        int mask_end=pow(3,m);
        for(int i=0;i<mask_end;i++){
            vector<int>color;
            int mm=i;
            for(int j=0;j<m;j++){
                color.push_back(mm%3);
                mm/=3;
            }
            int check=1;

            for(int j=0;j<m-1;j++){
                if(color[j]==color[j+1]){
                    check=0;
                    break;
                }
            }
            if(check)valid[i]=move(color);
        }

        unordered_map<int,vector<int>>adj;
        for(auto &[mask,clr]:valid){
            for(auto &[mask2,clr2]:valid){
                int check=1;
                for(int i=0;i<m;i++){
                    if(clr[i]==clr2[i]){
                        check=0;
                        break;
                    }
                }
                if(check)adj[mask].push_back(mask2);
            }
        }

        vector<int>f(mask_end);
        for(auto &[mask,clr]:valid)f[mask]=1;

        for(int i=1;i<n;i++){
            vector<int>g(mask_end);
            for(auto &[mask2,clr2]:valid){
                for(int mask:adj[mask2]){
                    g[mask2]+=f[mask];
                    g[mask2]%=mod;
                }
            }
            f=move(g);
        }

        int ans=0;
        for(auto &c:f)ans+=c,ans%=mod;
        return ans;
    }
};

// Time Complexity : O((3^(2m))*n) => O(4^N);
// Space Complexity: O(3^(2m)) => O(3^N);