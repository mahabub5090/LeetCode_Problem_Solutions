// Problem Link: https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/description/?envType=daily-question&envId=2026-08-14

class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<int,int> mp;
        int i=0, j=0, n=s.size();
        int ans=0;

        while(j<n){
            mp[s[j++]]++;

            while(mp[s[j-1]]>2) mp[s[i++]]--;
            ans=max(ans,j-i);
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(26) => O(1);