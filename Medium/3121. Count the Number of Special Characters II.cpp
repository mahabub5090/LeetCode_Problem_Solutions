// Problem Link: https://leetcode.com/problems/count-the-number-of-special-characters-ii/description/?envType=daily-question&envId=2026-05-27

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lower(26,-1), upper(26,-1);
        for(int i=0;i<word.size();i++){
            char c=word[i];
            if(isupper(c) && upper[c-'A']==-1) upper[c-'A']=i;
            if(islower(c)) lower[c-'a']=i;
        }

        int cnt=0;
        for(int i=0;i<26;i++){
            if(lower[i]==-1 || upper[i]==-1) continue;
            if(lower[i]<upper[i]) cnt++;
        }
        return cnt;
    }
};

// Time Complexity : O(N) + O(26) => O(N);
// Space Complexity: O(26) + O(26) => O(1);