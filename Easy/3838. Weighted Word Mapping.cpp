// Problem Link: https://leetcode.com/problems/weighted-word-mapping/description/?envType=daily-question&envId=2026-06-13

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(auto &word:words){
            int cnt=0;
            for(auto &c:word) cnt+=weights[c-'a'];
            cnt%=26;
            ans+=(char)'a'+(25-cnt);
        }
        return ans;
    }
};

// Time Complexity : O(N*M);
// Space Complexity: O(1);
// N=words.size(), M=words[i].size();