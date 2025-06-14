// Problem Link: https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/description/?envType=daily-question&envId=2025-06-14

class Solution {
public:
    int minMaxDifference(int num) {
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
        for(auto &c:s){
            if(c==s[0])s2+='0';
            else s2+=c;
        }
        int mn=stoi(s2);
        return mx-mn;
    }
};

// Time Complexity : O(6*9) => O(1);
// Space Complexity: O(9) => O(1);