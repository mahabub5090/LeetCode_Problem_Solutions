// Problem Link: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/

class Solution {
public:
    int minAddToMakeValid(string s) {
        string st="";
        for(auto &c:s){
            if(st=="")st+=c;
            else if(st.back()=='(' && c==')')st.pop_back();
            else st+=c;
        }
        return st.size();
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);