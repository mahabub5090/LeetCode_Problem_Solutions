// Problem Link: https://leetcode.com/problems/clear-digits/description/?envType=daily-question&envId=2025-02-10

class Solution {
    public:
        string clearDigits(string s) {
            string ans="";
            for(int i=0;i<s.size();i++){
                if(s[i]>='0' && s[i]<='9')ans.pop_back();
                else ans+=s[i];
            }
            return ans;
        }
    };
    
    // Time Complexity : O(N);
    // Space Complexity: O(1);