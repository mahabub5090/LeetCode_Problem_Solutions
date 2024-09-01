// Problem Link: https://leetcode.com/problems/hash-divided-string/description/

class Solution {
public:
    string stringHash(string s, int k) {
        vector<pair<string,int>>vc;
        string c=""; int sum=0;
        for(int i=0;i<s.size();i++){
            c+=s[i];
            sum+=s[i]-'a';
            if(c.size()==k){
                vc.push_back({c,sum});
                c="";sum=0;
            }
        }
        string ans="";
        for(auto &c:vc){
            ans+=('a'+c.second%26);
        }
        return ans;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(N);