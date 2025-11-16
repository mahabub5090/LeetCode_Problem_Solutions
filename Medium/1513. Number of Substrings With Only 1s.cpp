// Problem Link: https://leetcode.com/problems/number-of-substrings-with-only-1s/description/?envType=daily-question&envId=2025-11-16

class Solution {
public:
    int numSub(string s) {
        long long ans=0;
        long long cnt=0,mod=1e9+7;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')cnt++;
            else{
                ans+=(cnt*(cnt+1))/2;
                ans%=mod;
                cnt=0;
            }
        }
        ans+=(cnt*(cnt+1))/2;
        ans%=mod;
        return (int)ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);