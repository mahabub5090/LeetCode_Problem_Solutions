// Problem Link: https://leetcode.com/problems/stone-game-ix/description/?envType=daily-question&envId=2026-08-16

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int remZero=0, remOne=0, remTwo=0;
        for(auto &c:stones){
            int rem=c%3;
            remZero+=rem==0;
            remOne+=rem==1;
            remTwo+=rem==2;
        }
        
        if(remZero%2==0) return remOne>0 && remTwo>0;
        return abs(remOne-remTwo)>2;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);