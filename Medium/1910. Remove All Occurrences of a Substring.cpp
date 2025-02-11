// Problem Link: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/?envType=daily-question&envId=2025-02-11

class Solution {
    public:
        string removeOccurrences(string s, string part) {
            int n=s.size(),m=part.size();
            stack<char>st;
            for(auto &c:s){
                st.push(c);
                if(st.size()>=m && st.top()==part.back()){
                    string cmp="";
                    int i=0;
                    while(i++<m)cmp+=st.top(),st.pop();
                    reverse(cmp.begin(),cmp.end());
                    cout<<cmp<<endl;
    
                    if(cmp!=part){
                        for(auto &cc:cmp)st.push(cc);
                    }
                }
            }
            string ans="";
            while(st.size())ans+=st.top(),st.pop();
            reverse(ans.begin(),ans.end());
            return ans;
        }
    };
    
    // Time Complexity : O(N*M) => O(N^2);
    // Space Complexity: O(N+M) => O(N);