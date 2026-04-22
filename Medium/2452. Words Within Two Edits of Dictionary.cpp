// Problem Link: https://leetcode.com/problems/words-within-two-edits-of-dictionary/description/?envType=daily-question&envId=2026-04-22

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;
        for(auto &s:queries){
            for(auto &c:dictionary){
                int cnt=0,len=s.size();
                for(int i=0;i<len;i++){
                    if(s[i]==c[i])cnt++;
                }
                if(cnt+2>=len){
                    ans.push_back(s);
                    break;
                }
            }
        }
        return ans;
    }
};

// Time Complexity : O(N*M*L) => O(N^3);
// Space Complexity: O(N);
// N = queries.size(), M = dictionary.size(), L = queries[0].size();