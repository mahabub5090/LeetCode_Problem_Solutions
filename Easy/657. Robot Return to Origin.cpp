// Problem Link: https://leetcode.com/problems/robot-return-to-origin/description/?envType=daily-question&envId=2026-04-05

class Solution {
public:
    bool judgeCircle(string moves) {
        int x=0,y=0;
        for(auto &c:moves){
            x-=c=='L';
            x+=c=='R';
            y-=c=='D';
            y+=c=='U';
        }
        return x==0 && y==0;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);