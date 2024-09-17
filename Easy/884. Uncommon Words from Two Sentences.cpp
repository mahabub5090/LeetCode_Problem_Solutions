// Problem Link: https://leetcode.com/problems/uncommon-words-from-two-sentences/description/?envType=daily-question&envId=2024-09-17

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string,int>mp;
        stringstream first(s1),second(s2);
        string c="";
        while(first>>c){
            mp[c]++;
        }
        c="";
        while(second>>c){
            mp[c]++;
        }
        vector<string>ans;
        for(auto &c:mp){
            if(c.second==1)ans.push_back(c.first);
        }
        return ans;
    }
};

// Time Complexity : O(3*N) => O(N);
// Space Complexity: O(N);