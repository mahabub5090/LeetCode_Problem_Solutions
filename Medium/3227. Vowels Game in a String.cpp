// Problem Link: https://leetcode.com/problems/vowels-game-in-a-string/description/?envType=daily-question&envId=2025-09-12

class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt=0;
        for(auto &c:s)cnt+=(string("aeiouAEIOU").find(c)!=string::npos);
        return cnt>0;
    }
};