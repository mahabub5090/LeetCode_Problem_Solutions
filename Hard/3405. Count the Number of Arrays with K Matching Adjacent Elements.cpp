// Problem Link: https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/description/?envType=daily-question&envId=2025-06-17

class Solution {
public:
    int mod=1e9+7,mx=1e5;

    long long pw(long long x,int n){
        long long ans=1;
        while(n){
            if(n%2)ans=(ans*x)%mod;
            x=(x*x)%mod;
            n/=2;
        }
        return ans;
    }

    void init(auto &fact,auto &invFact){
        fact[0]=1;
        for(int i=1;i<mx;i++){
            fact[i]=(fact[i-1]*i)%mod;
        }
        invFact[mx-1]=pw(fact[mx-1],mod-2);
        for(int i=mx-1;i>0;i--){
            invFact[i-1]=(invFact[i]*i)%mod;
        }
    }

    long long comb(int n,int m,auto &fact,auto &invFact){
        return (((fact[n]*invFact[m])%mod)*invFact[n-m])%mod;
    }
    int countGoodArrays(int n, int m, int k) {
        vector<long long>fact(mx),invFact(mx);
        init(fact,invFact);
        return ((comb(n-1,k,fact,invFact)*m)%mod)*(pw(m-1,n-k-1))%mod;
    }
};

// Time Complexity : O(N) * O(logN) => O(NlogN);
// Space Complexity: O(2*N) => O(N);