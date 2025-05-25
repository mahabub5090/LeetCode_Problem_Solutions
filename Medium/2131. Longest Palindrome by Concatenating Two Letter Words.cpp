// Problem Link: https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/description/?envType=daily-question&envId=2025-05-25

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        int ans=0;
        for(auto &c:words)mp[c]++;
        for(auto &c:words){
            if(mp[c]==0)continue;
            mp[c]--;
            string s=c;
            reverse(s.begin(),s.end());
            if(mp[s])ans+=4,mp[s]--;
            else mp[c]++;
        }
        for(auto &c:mp){
            if(c.second==0)continue;
            if(c.first[0]==c.first[1]){
                ans+=2;
                break;
            }
        }
        return ans;
    }
};

// Time Complexity : O(N*2) => O(N);
// Space Complexity: O(N*2) => O(N);