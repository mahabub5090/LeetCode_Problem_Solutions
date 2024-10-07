// Problem Link: https://leetcode.com/problems/minimum-string-length-after-removing-substrings/submissions/1414638694/?envType=daily-question&envId=2024-10-07

class Solution {
public:
    int minLength(string s) {
        stack<char>st;
        for(auto &c:s){
            if(st.empty())st.push(c);
            else{
                if(c=='B' || c=='D'){
                    if(st.top()=='A' && c=='B')st.pop(); 
                    else if(st.top()=='C' && c=='D')st.pop(); 
                    else st.push(c);
                }
                else st.push(c);
            }
        }
        return st.size();
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);