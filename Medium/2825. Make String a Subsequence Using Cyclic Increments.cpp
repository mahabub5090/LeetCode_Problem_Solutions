/// Problem Link: https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/description/?envType=daily-question&envId=2024-12-04

class Solution {
public:
    char next(char c){
        if(c=='z')return 'a';
        return c+1;
    }
    bool canMakeSubsequence(string str1, string str2) {
        int i=0;
        for(auto &c:str2){
            while(i<str1.size() && (c!=str1[i] && c!=next(str1[i])))i++;
            i++;
            if(i>str1.size())return 0;
        }
        return 1;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);