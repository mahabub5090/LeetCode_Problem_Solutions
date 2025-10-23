// Problem Link: https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/description/?envType=daily-question&envId=2025-10-23

class Solution {
public:
    bool hasSameDigits(string s) {
        string temp="";
        while(s.size()!=2){
            temp="";
            for(int i=0;i<s.size()-1;i++){
                temp+='0'+((s[i]-'0'+s[i+1]-'0')%10);
            }
            s=temp;
        }
        return s[0]==s[1];
    }
};

// Time Complexity : O(N^2);
// Space Complexity: O(1);