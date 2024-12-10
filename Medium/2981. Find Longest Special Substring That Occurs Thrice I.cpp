// Problem Link: https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/submissions/1475363849/?envType=daily-question&envId=2024-12-10

class Solution {
public:
    bool speacial(auto s){
        set<char>st;for(auto &c:s)st.insert(c);
        return st.size()==1;
    }
    int maximumLength(string s) {
        map<string,int>mp;
        string cmp="";
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                cmp=s.substr(i,j-i+1);
                if(speacial(cmp))mp[cmp]++;
            }
        }
        int ans=0;
        for(auto &c:mp){
            if(c.second>=3)ans=max(ans,(int)c.first.size());
        }
        return ans?ans:-1;
    }
};

// Time Complexity : O(N^3);
// Space Complexity: O(N^2); 