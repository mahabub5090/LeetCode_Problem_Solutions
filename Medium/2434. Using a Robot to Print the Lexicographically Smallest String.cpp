// Problem Link: https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/description/?envType=daily-question&envId=2025-06-06

class Solution {
public:
    int find(auto &cnt){
        int mn=0;
        while(mn<26 && cnt[mn]==0)mn++;
        return mn;
    }
    string robotWithString(string s) {
        vector<int>cnt(26,0);
        for(auto &c:s)cnt[c-'a']++;
        int n=s.size();
        stack<char>st;
        string ans="";
        for(int i=0;i<n;i++){
            int pos=s[i]-'a';
            cnt[pos]--;
            
            st.push(s[i]);
            int mn=find(cnt);
            while(st.size() && (st.top()<=('a'+mn))){
                    ans+=st.top();
                    st.pop();
            }
        }
        while(st.size())ans+=st.top(),st.pop();
        return ans;
    }
};

// Time Complexity : O(N*26) => O(N);
// Space Complexity: O(N);