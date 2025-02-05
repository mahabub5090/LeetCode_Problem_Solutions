// Problem Link: https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/description/?envType=daily-question&envId=2025-02-05

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt=0;
        vector<int>vc(26,0),vc2(26,0);
        for(int i=0;i<s1.size();i++){
            cnt+=s1[i]!=s2[i];
            vc[s1[i]-'a']++;
            vc2[s2[i]-'a']++;
        }
        return (cnt==0 || cnt==2) && vc==vc2;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(2*26) => O(1);