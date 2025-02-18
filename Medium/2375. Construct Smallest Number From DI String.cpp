// Problem Link: https://leetcode.com/problems/construct-smallest-number-from-di-string/description/?envType=daily-question&envId=2025-02-18

class Solution {
    public:
        string smallestNumber(string pattern) {
            int n=pattern.size();
            string ans="";
            stack<int>st;
            for(int i=0;i<=pattern.size();i++){
                st.push(i+1);
                while(st.size() && (i==n || pattern[i]=='I')){
                    ans+='0'+(st.top());
                    st.pop();
                }
            }
            while(st.size())ans+='0'+st.top(),st.pop();
            return ans;
        }
};
    
// Time Complexity : O(N);
// Space Complexity: O(N);