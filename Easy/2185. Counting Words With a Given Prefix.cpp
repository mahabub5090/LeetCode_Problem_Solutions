// Problem Link: https://leetcode.com/problems/counting-words-with-a-given-prefix/description/?envType=daily-question&envId=2025-01-09

class Solution {
public:
    int isPrefix(string s,string s2){
        if(s.size()>s2.size())return 0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=s2[i])return 0;
        }
        return 1;
    }
    int prefixCount(vector<string>& words, string pref) {
        int ans=0;
        for(auto &c:words)ans+=isPrefix(pref,c);
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);