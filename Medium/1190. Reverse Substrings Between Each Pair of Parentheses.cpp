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
//==========================;
// way-2 (Most optimize solution) =>

class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        vector<int>pair(n,-1);
        stack<int>open;
        for(int i=0;i<n;i++){
            if(s[i]=='(')open.push(i);
            else if(s[i]==')'){
                pair[open.top()]=i;
                pair[i]=open.top();
                open.pop();
            }
        }
        string ans="";
        for(int i=0,dir=1;i<n;i+=dir){
            if(s[i]=='(' || s[i]==')'){
                i=pair[i];
                dir*=-1;
            }
            else{
                ans+=s[i];
            }
        }
        return ans;

    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(2*N) => O(N);