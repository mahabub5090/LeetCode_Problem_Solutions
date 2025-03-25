// Problem Link:  https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/description/?envType=daily-question&envId=2025-03-25

class Solution {
public:
    int countInterval(auto &vc){
        sort(vc.begin(),vc.end());
        int cnt=0,prev=-1;
        for(auto &c:vc){
            if(c.first>=prev)cnt++;
            prev=max(prev,c.second);
        }
        return cnt;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int,int>>x,y;
        for(auto &c:rectangles){
            x.push_back({c[0],c[2]});
            y.push_back({c[1],c[3]});
        }
        return max(countInterval(x),countInterval(y))>=3;
    }
};

// Time Complexity : O(RlogR) => O(NlogN);
// Space Complexity: O(R) => O(N);
// R is rectangles.size() here;