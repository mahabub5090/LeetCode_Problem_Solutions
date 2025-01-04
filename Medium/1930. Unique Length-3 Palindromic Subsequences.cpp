// Problem Link: https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/?envType=daily-question&envId=2025-01-04

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        map<char,int>mp;
        for(auto &c:s)mp[c]++;
        set<char>st;
        set<string>ans;
        string cmp="";
        for(auto &c:s){
            mp[c]--;
            for(auto &cc:st){
                if(mp[cc]>0){
                    cmp+=c;cmp+=cc;
                    ans.insert(cmp);
                    cmp="";
                }
            }
            st.insert(c);
        }
        return ans.size();
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);