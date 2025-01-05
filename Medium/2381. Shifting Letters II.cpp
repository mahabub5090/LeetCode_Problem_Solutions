// Problem Link: https://leetcode.com/problems/shifting-letters-ii/description/?envType=daily-question&envId=2025-01-05

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int>pref(n+1,0);
        for(auto &c:shifts){
            pref[c[1]+1]+=c[2]?1:-1;
            pref[c[0]]+=c[2]?-1:1;
        }
        int diff=pref[n];
        for(int i=n-1;i>=0;i--){
            diff%=26;
            s[i]='a'+((s[i]-'a')+diff+26)%26;
            diff+=pref[i];
        }
        return s;
    }
};

// Time Complexity : O(N+M) => O(N); 
// Space Complexity: O(N);
// M is the size of shifts vector;