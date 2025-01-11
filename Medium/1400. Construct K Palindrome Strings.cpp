// Problem Link: https://leetcode.com/problems/construct-k-palindrome-strings/description/?envType=daily-question&envId=2025-01-11

class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int>vc(26,0);
        for(auto &c:s)vc[c-'a']++;
        int cnt=0,cnt2=0;
        for(auto &c:vc)cnt+=c,cnt2+=c%2;
        return cnt>=k && cnt2<=k ;
    }
};

// TIme Complexity : O(N);
// Space Complexity: O(26) => O(1);