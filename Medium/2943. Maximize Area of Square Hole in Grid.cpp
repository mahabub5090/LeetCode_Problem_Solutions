// Problem Link: https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/description/?envType=daily-question&envId=2026-01-15

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        int maxh=1,maxv=1,currh=1,currv=1;
        for(int i=1;i<hBars.size();i++){
            if(hBars[i]==hBars[i-1]+1)currh++;
            else currh=1;
            maxh=max(maxh,currh);
        }
        for(int i=1;i<vBars.size();i++){
            if(vBars[i]==vBars[i-1]+1)currv++;
            else currv=1;
            maxv=max(maxv,currv);
        }

        int len=min(maxh,maxv)+1;
        return len*len;
    }
};

// Time Complexity : O(NlogN) + O(MlogM) => O(NlogN);
// Space Complexity: O(1);