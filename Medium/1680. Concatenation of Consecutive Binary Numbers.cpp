// Problem Link: https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/description/?envType=daily-question&envId=2026-02-28

class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans=1,mod=1e9+7;
        for(int i=2;i<=n;i++){
            int curr=i;
            string s="";
            while(curr)s+='0'+(curr&1),curr>>=1;
            reverse(s.begin(),s.end());

            for(auto &c:s){
                ans<<=1;
                ans|=(c-'0');
                ans%=mod;
            }
        }
        return ans;
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(1);