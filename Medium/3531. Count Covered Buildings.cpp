// Problem Link: https://leetcode.com/problems/count-covered-buildings/description/?envType=daily-question&envId=2025-12-11

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<pair<int,int>>rows(n,{INT_MAX,0}),cols=rows;
        for(auto &c:buildings){
            auto &i=rows[--c[0]];
            auto &j=cols[--c[1]];
            i={min(i.first,c[1]),max(i.second,c[1])};
            j={min(j.first,c[0]),max(j.second,c[0])};
        }
        
        int ans=0;
        for(auto &c:buildings){
            if(c[0]==0 || c[0]==n-1 || c[1]==0 || c[1]==n-1)continue;   
            auto &i=rows[c[0]];
            auto &j=cols[c[1]];
            if(i.first<c[1] && i.second>c[1] && j.first<c[0] && j.second>c[0])ans++;
        }
        return ans;
    }
};

// Time Complexity : O(2*M) => O(N);
// Space Complexity: O(2*N) => O(N);
// M is the size of "buildings".
