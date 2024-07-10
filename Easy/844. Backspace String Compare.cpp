// Problem Link: https://leetcode.com/problems/backspace-string-compare/description/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int cnt=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='#')cnt++;
            else if(cnt)cnt--,s[i]='#';
        }
        cnt=0;
        for(int i=t.size()-1;i>=0;i--){
            if(t[i]=='#')cnt++;
            else if(cnt)cnt--,t[i]='#';
        }
        int a=0,b=0;
        for(auto &c:s)if(c!='#')a++;
        for(auto &c:t)if(c!='#')b++;
        if(a!=b)return 0;
        int i=0,j=0;
        while(true){
            while(i<s.size() && s[i]=='#')i++;
            while(j<t.size() && t[j]=='#')j++;
            if(i==s.size() || j==t.size())break;
            if(s[i]!=t[j])return 0;
            i++,j++;
        }
        return 1;
    }
};

// Time Complexity => O(N)
// Space Complexity => O(1)