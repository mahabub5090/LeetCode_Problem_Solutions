// Problem Link: https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/description/?envType=daily-question&envId=2026-03-29

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        for(int i=0;i<4;i++){
            if(s1[i]==s2[i])continue;
            if(i+2<4 && s1[i]==s2[i+2])swap(s2[i],s2[i+2]);
            else return 0;
        }
        return 1;
    }
};

// Time Complexity : O(4) => O(1);
// Space Complexity: O(1);