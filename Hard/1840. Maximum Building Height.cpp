// Problem Link: https://leetcode.com/problems/maximum-building-height/description/?envType=daily-question&envId=2026-06-20

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1,0});
        sort(restrictions.begin(),restrictions.end());
        if(restrictions.back()[0]!=n) restrictions.push_back({n,n-1});

        auto &vc=restrictions;

        int m=vc.size();
        for(int i=1;i<m;i++){
            int dis=vc[i][0]-vc[i-1][0];
            vc[i][1]=min(vc[i][1],vc[i-1][1]+dis);
        }
        for(int i=m-2;i>=0;i--){
            int dis=vc[i+1][0]-vc[i][0];
            vc[i][1]=min(vc[i][1],vc[i+1][1]+dis);
        }

        int ans=0;
        for(int i=0;i<m-1;i++){
            int dis=vc[i+1][0]-vc[i][0];
            int curr=(dis+vc[i][1]+vc[i+1][1])/2;
            ans=max(ans,curr);
        }
        return ans;
    }
};

// Time Complexity : O(MlogM) + O(M) + O(M) + O(M) => O(MlogM);
// Space Complexity: O(logM); // for sorting;
// M = restrictions.size();