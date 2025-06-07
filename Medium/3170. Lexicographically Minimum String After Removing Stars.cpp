// Problem Link: https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/description/?envType=daily-question&envId=2025-06-07

class Solution {
public:
    string clearStars(string s) {
        vector<stack<int>>cnt(26);
        for(int i=0;i<s.size();i++){
            if(s[i]!='*')cnt[s[i]-'a'].push(i);
            else{
                for(int j=0;j<26;j++){
                    if(cnt[j].size()){
                        s[cnt[j].top()]='*';
                        cnt[j].pop();
                        break;
                    }
                }
            }
        }
        string ans="";
        for(auto &c:s)if(c!='*')ans+=c;
        return ans;
    }
};

// Time Complexity : O(N*26) => O(N);
// Space Complexity: O(26+N) => O(N);