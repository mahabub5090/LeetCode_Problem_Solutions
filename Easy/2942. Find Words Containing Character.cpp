// Problem Link: https://leetcode.com/problems/find-words-containing-character/description/?envType=daily-question&envId=2025-05-24

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>ans;
        int cnt=0;
        for(auto &c:words){
            if(count(c.begin(),c.end(),x))ans.push_back(cnt);
            cnt++;
        }
        return ans;
    }
};

// Time Complexity : O(N*words[i].size()) => O(N^2);
// Space Complexity: O(N);