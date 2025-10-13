// Problem Link: https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/description/?envType=daily-question&envId=2025-10-13

class Solution {
public:
    vector<int> charCnt(string &s){
        vector<int>ans(26,0);
        for(auto &c:s)ans[c-'a']++;
        return ans;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        map<string,vector<int>>mp;
        for(auto &c:words)mp[c]=charCnt(c);
        vector<string>ans;
        int n=words.size();
        for(int i=0;i<n;i++){
            ans.push_back(words[i]);
            int j=i+1;
            while(j<n && mp[words[i]]==mp[words[j]])j++;
            i=j-1;
        }
        return ans;
    }
};

// Time Complexity : O(N) * O(L) => O(N^2);
// Space Complexity: O(N) * O(L) => O(N^2);
// L is maximum length of words[i];