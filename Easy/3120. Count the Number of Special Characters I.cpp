// Problem Link: https://leetcode.com/problems/count-the-number-of-special-characters-i/description/?envType=daily-question&envId=2026-05-26

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> upper(26,0), lower(26,0);
        for(auto &c:word){
            if(isupper(c)) upper[c-'A']++;
            else lower[c-'a']++;
        }

        int ans=0;
        for(int i=0;i<26;i++) ans+=(lower[i] && upper[i]);
        return ans;
    }
};

// Time Complexity : O(N) + O(26) => O(N);
// Space Complexity: O(26) + O(26) => O(1);