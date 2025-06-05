// Problem Link: https://leetcode.com/problems/lexicographically-smallest-equivalent-string/description/?envType=daily-question&envId=2025-06-05

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<set<char>>vc(26);
        int n=s1.size();
        for(int i=0;i<n;i++){
            vc[s1[i]-'a'].insert(s2[i]);
            vc[s2[i]-'a'].insert(s1[i]);  
        }
        for(int i=0;i<26;i++){
            for(auto &c:vc[i]){
                vc[c-'a'].insert('a'+i);
                for(auto &cc:vc[c-'a']){
                    vc[i].insert(cc);
                    vc[cc-'a'].insert('a'+i);
                }
            }
        }
        string ans="";
        for(int i=0;i<baseStr.size();i++){
            char c=baseStr[i];
            set<char>st;
            st.insert(c);
            
            for(auto &c:st){
                for(auto &cc:vc[c-'a']){
                    st.insert(cc);
                }
            }
            
            if(st.size())ans+=*st.begin();
            else ans+=c;
        }
        return ans;
    }
};

// Time Complexity : O(N*26*26) => O(N);
// Space Complexity: O(26*26) => O(1);