// Problem Link: https://leetcode.com/problems/find-valid-pair-of-adjacent-digits-in-string/description/

class Solution {
public:
    string findValidPair(string s) {
        map<int,int>mp;
        for(auto &c:s)mp[c-'0']++;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]==s[i+1])continue;
            if(mp[s[i]-'0']==s[i]-'0' && mp[s[i+1]-'0']==s[i+1]-'0'){
                ans+=s[i];
                ans+=s[i+1];
                return ans;
            }
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);