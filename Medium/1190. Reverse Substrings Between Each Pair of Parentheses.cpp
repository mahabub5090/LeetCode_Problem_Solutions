// Problem Link: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/?envType=daily-question&envId=2024-07-11

class Solution {
public:
    void reverseString(string &s,int i,int j){
       int mid=j-i+1;
       mid/=2;
       mid+=i;
       while(i<mid){
        swap(s[i],s[j]);
        i++;j--;
       }
    }

    string reverseParentheses(string s) {
        int i=0,j=0;
        while(true){
            while(j<s.size() && s[j]!=')')j++;
            i=j-1;
            while(i>=0 && s[i]!='(')i--;
            if(i>=0)s[i]=')';
            if(i<0 || j>=s.size())break;
            reverseString(s,i,j);
            j++;
        }
        string ans="";
        for(auto &c:s)if(c!=')')ans+=c;
        return ans;
    }
};

// Time Complexity => O(N^2)
// Space Complexity => O(1)