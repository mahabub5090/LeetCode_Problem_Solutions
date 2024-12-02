// Problem Link: https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/description/?envType=daily-question&envId=2024-12-02

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int cnt=0;
        string cmp="";
        stringstream ss(sentence);
        while(ss>>sentence){
            cnt++;
            for(auto &c:sentence){
                cmp+=c;
                if(cmp==searchWord)return cnt;
            }
            cmp="";
        }
        return -1;
    }
};

// Time Complexity : O(N*N) => O(N^2);
// Space Complexity: O(1);