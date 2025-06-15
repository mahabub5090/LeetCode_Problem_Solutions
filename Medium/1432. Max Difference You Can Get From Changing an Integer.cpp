// Problem Link: https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/description/?envType=daily-question&envId=2025-06-15

class Solution {
public:
    int maxDiff(int num) {
        string s=to_string(num);
        int i=0;
        while(i<s.size() && s[i]=='9')i++;
        string s2="";
        for(auto &c:s){
            if(i<s.size() && c==s[i])s2+='9';
            else s2+=c;
        }
        int mx=stoi(s2);
        s2="";
        i=1;
        while(i<s.size() && (s[i]==s[0] || s[i]=='0'))i++;
        for(auto &c:s){
            if(i<s.size() && c==s[i])s2+='0';
            else s2+=c;
        }
        string s3="";
        if(s2==s){
            for(auto &c:s)s3+='1';
        }
        else{
            s3="";
            for(auto &c:s){
                if(c==s[0])s3+='1';
                else s3+=c;
            }
        }
        int mn=min(stoi(s2),stoi(s3));
        return mx-mn;
    }
};

// Time Complexity : O(9*num.size()) => O(9*8) => O(1);
// Space Complexity: O(1);
// maximam num.size() is 8 here.