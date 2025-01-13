// Problem Link: https://leetcode.com/problems/minimum-length-of-string-after-operations/description/?envType=daily-question&envId=2025-01-13

class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        vector<int>l(26,0),r(26,0);
        for(auto &c:s)r[c-'a']++;
        int cnt=0;
        for(auto &c:s){
            if(l[c-'a'] && r[c-'a']-1>0){
                int mn=min(l[c-'a'],r[c-'a']-1);
                cnt+=mn*2;
                l[c-'a']-=mn;
                r[c-'a']-=mn;
            }
            l[c-'a']++,r[c-'a']--;
        }
        return n-cnt;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(2*26) => O(1);