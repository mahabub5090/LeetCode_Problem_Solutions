// Problem Link: https://leetcode.com/problems/count-good-numbers/description/?envType=daily-question&envId=2025-04-13

class Solution {
public:
    long long pw(long long base,long long expo,int mod){
        long long ans=1;
        while(expo){
            if(expo%2)ans=(ans*base)%mod;
            base*=base;
            base%=mod;
            expo/=2;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long ans=1;
        long long mod=1e9+7;
        long long even=pw(4,n/2,mod),odd=pw(5,n-n/2,mod);
        ans*=even,ans%=mod;
        ans*=odd,ans%=mod;
        return ans;
    }
};

// Time Complexity : O(logN);
// Space Complexity: O(1);
