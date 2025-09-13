// Problem Link: https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/description/?envType=daily-question&envId=2025-09-13

class Solution {
public:
    int maxFreqSum(string s) {
        vector<int>freq(26,0);
        for(auto &c:s)freq[c-'a']++;
        int mx=0,mx2=0;
        for(int i=0;i<26;i++){
            if(string("aeiou").find(i+'a')!=string::npos)mx=max(mx,freq[i]);
            else mx2=max(mx2,freq[i]);
        }
        return mx+mx2;
    }
};

// Time Complexity : O(N) + O(26*5) => O(N);
// Space Complexity: O(26) => O(1);