// Problem Link: https://leetcode.com/problems/separate-squares-i/description/?envType=daily-question&envId=2026-01-13

class Solution {
public:
    int check(double mid,auto &sq){
        double tt=0,area=0;

        for(auto &c:sq){
            tt+=(double)c[2]*c[2];
            if(c[1]<mid)area+=c[2]*min(mid-c[1],(double)c[2]);
        }
        return area>=tt/2;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double l=0,r=0,ac=1e-5;

        for(auto &c:squares)r=max(r,(double)c[1]+c[2]);
    
        while(abs(r-l)>ac){
            double mid=(l+r)/2;
            if(check(mid,squares))r=mid;
            else l=mid;
        }
        return l;
    }
};

// Time Complexity : O(N * log(1e9*1e5)) => O(NlogN);
// Space Complexity: O(1);