// Problem Link: https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/description/?envType=daily-question&envId=2025-06-26

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int cnt0=0,cnt1=0,n=s.size();
        for(auto &c:s)c=='0'?cnt0++:cnt1++;
        long long num=0,ans=cnt0;
        for(int i=n-1;i>=max(0,n-32);i--){
            if(s[i]=='1'){
                long long add=pow(2,n-i-1);
                if(num+add<=k){
                    num+=add;
                    ans++;
                }
                else break;
            }
        }
        return ans;
    }
};

// Time Complexity : O(2*N) => O(N);
// Time Complexity : O(1);