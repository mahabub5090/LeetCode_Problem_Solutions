// Problem Link: https://leetcode.com/problems/set-intersection-size-at-least-two/description/?envType=daily-question&envId=2025-11-20

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](auto &c,auto &d){
            return c[1]==d[1]?c[0]>d[0]:c[1]<d[1];
        });

        int cnt=2,n=intervals.size();
        int e=intervals[0][1],s=e-1;
        
        for(int i=1;i<n;i++){
            int l=intervals[i][0],r=intervals[i][1];
            if(s>=l)continue;
            int flag=l>e;
            ++cnt+=flag;
            s=flag?r-1:e;
            e=r;
        }
        return cnt;
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(1);