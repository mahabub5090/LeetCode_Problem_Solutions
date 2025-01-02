// Problem Link: https://leetcode.com/problems/count-vowel-strings-in-ranges/description/?envType=daily-question&envId=2025-01-02

class Solution {
public:
    bool isV(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int>pref(n,0);
        for(int i=0;i<n;i++){
            if(isV(words[i][0]) && isV(words[i][words[i].size()-1]))pref[i]++;
        }
        for(int i=1;i<n;i++)pref[i]+=pref[i-1];
        vector<int>ans;
        for(auto &c:queries){
            ans.push_back(pref[c[1]]-(!c[0]?0:pref[c[0]-1]));
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);