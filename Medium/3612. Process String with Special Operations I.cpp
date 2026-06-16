// Problem Link: https://leetcode.com/problems/process-string-with-special-operations-i/description/?envType=daily-question&envId=2026-06-16

class Solution {
public:
    string processStr(string s) {
        string result="";
        for(auto &c:s){
            if(c=='*'){
                if(result.size()) result.pop_back();
            }
            else if(c=='#') result+=result;
            else if(c=='%') reverse(result.begin(),result.end());
            else result+=c;
        }
        return result;
    }
};

// Time Complexity : O(2^N);
// Space Complexity: O(2^N);