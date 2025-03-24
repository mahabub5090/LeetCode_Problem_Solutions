// Problem Link: https://leetcode.com/problems/count-days-without-meetings/description/?envType=daily-question&envId=2025-03-24

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end(),[](auto &a,auto &b){return a[0]<b[0];});
        int ans=0;
        int i=0;
        for(auto &c:meetings){
            if(c[1]<i)continue;
            else if(c[0]<i)i=c[1];
            else{
                ans+=max(0,c[0]-i-1);
                i=c[1];
            }
        }
        ans+=days-i;
        return ans;
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(1);