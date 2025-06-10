// Problem Link: https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/description/?envType=daily-question&envId=2025-06-10

class Solution {
public:
    int maxDifference(string s) {
        vector<int>cnt(26);
        for(auto &c:s)cnt[c-'a']++;
        int mx=0,mn=INT_MAX;
        for(auto &c:cnt){
            if(c%2)mx=max(mx,c);
            if(c && c%2==0)mn=min(mn,c);
        }
        return mx-mn;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(26) => O(1);