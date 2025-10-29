// Problem Link: https://leetcode.com/problems/smallest-number-with-all-set-bits/description/?envType=daily-question&envId=2025-10-29

class Solution {
public:
    int smallestNumber(int n) {
        string s=bitset<32>(n).to_string();
        reverse(s.begin(),s.end());
        while(s.back()=='0')s.pop_back();
        reverse(s.begin(),s.end());
        int len=s.size();
        s="";
        for(int i=0;i<len;i++)s+='1';
        return stoi(s,NULL,2);
    }
};

// Time Complexity : O(1);
// Space Complexity: O(1);