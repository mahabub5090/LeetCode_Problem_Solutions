// Problem Link: https://leetcode.com/problems/removing-stars-from-a-string/description/

class Solution {
public:
    string removeStars(string s) {
        int cnt=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='*')cnt++;
            else if(cnt)cnt--,s[i]='*';
        }
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]!='*')ans+=s[i];
        }
        return ans;
    }
};