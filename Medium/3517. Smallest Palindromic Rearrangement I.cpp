// Problem Link: https://leetcode.com/problems/smallest-palindromic-rearrangement-i/description/?envType=daily-question&envId=2026-07-28

class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> cnt(26,0);
        for(auto &c:s) cnt[c-'a']++;
        
        int l=0, r=s.size()-1;
        for(int i=0;i<26;i++){
            while(cnt[i]>=2){
                s[l++]='a'+i;
                s[r--]='a'+i;
                cnt[i]-=2;
            }
            if(cnt[i]) s[l+(r-l)/2]='a'+i;
        }
        return s;
    }
};

// Time Complexity : O(N) + O(26+N) => O(N);
// Space Complexity: O(26) => O(1);