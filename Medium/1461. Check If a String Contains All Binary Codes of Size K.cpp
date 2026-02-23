// Problem Link: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/description/?envType=daily-question&envId=2026-02-23

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>st;
        for(int i=0;i<(int)s.size()-k+1;i++){
            st.insert(s.substr(i,k));
        }
        return st.size()==1<<k;
    }
};

// Time Complexity : O(N*K);
// Space Complexity: O((2^K)*K);
// N<=5*1e5, K<=20;