// Problem Link: https://leetcode.com/problems/count-binary-substrings/description/?envType=daily-question&envId=2026-02-19

class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev=0,curr=1,n=s.size();
        int ans=0;
        for(int i=1;i<n;i++){
            if(s[i-1]==s[i])curr++;
            else{
                ans+=min(prev,curr);
                prev=curr;
                curr=1;
            }
        }
        ans+=min(prev,curr);
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);