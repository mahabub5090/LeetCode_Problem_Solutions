// Problem Link: https://leetcode.com/problems/permutation-in-string/submissions/1412648454/?envType=daily-question&envId=2024-10-05

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        if(n>m)return 0;
        unordered_map<char,int>mp,mp2;
        for(int i=0;i<n;i++)mp[s1[i]]++,mp2[s2[i]]++;
        for(int i=n;i<m;i++){
            if(mp==mp2)return 1;
            mp2[s2[i-n]]--;
            if(mp2[s2[i-n]]==0)mp2.erase(s2[i-n]);
            mp2[s2[i]]++;
            
        }
        return mp==mp2;
    }
};

// Time Complexity : O(N*26) => O(N);
// Space Complexity: O(2*26) => O(1);