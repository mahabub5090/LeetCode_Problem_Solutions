// Problem Link: https://leetcode.com/problems/find-sum-of-array-product-of-magical-sequences/description/?envType=daily-question&envId=2025-10-12

class Solution {
public:
    using ll=long long;
    int mod=1e9+7;

    ll modPow(ll n){
        ll r=1%mod,e=mod-2;
        n%=mod;
        while(e){
            if(e%2)r*=n,r%=mod;
            n=n*n%mod;
            e>>=1;
        }
        return r;
    }

    int magicalSum(int m, int k, vector<int>& nums) {
        int  n=nums.size();
        vector<ll>fact(m+1,1),ifact(m+1,1);
        for(int i=1;i<m+1;i++)fact[i]=fact[i-1]*i%mod;
        ifact[m]=modPow(fact[m]);
        for(int i=m-1;i>=0;i--)ifact[i]=ifact[i+1]*(i+1)%mod;

        vector<vector<ll>>aj(n,vector<ll>(m+1,0));
        for(int i=0;i<n;i++){
            ll base=(nums[i]%mod+mod)%mod;
            ll p=1;
            for(int j=0;j<m+1;j++){
                aj[i][j]=(p*ifact[j])%mod;
                p=p*base%mod;
            }
        }

        int T=m,C=m,O=k;
        vector<vector<vector<ll>>>dp_curr(T+1,vector<vector<ll>>(C+1,vector<ll>(O+1,0)));
        dp_curr[0][0][0]=1;

        for(int i=0;i<n;i++){
            vector<vector<vector<ll>>> dp_next(T+1,vector<vector<ll>>(C+1,vector<ll>(O+1,0)));
            for(int t=0;t<=T;t++){
                for(int c=0;c<=C;c++){
                    for(int o=0;o<=O;o++){
                         ll curr=dp_curr[t][c][o];
                         if(!curr)continue;

                         int maxc=T-t;
                         for(int cc=0;cc<=maxc;cc++){
                            int nt=t+cc;
                            int sum=c+cc;
                            int bit=sum&1;
                            int nc=sum>>1;
                            int no=o+bit;

                            if(no>O || nc>C)continue;

                            ll add=aj[i][cc];
                            ll val=(curr*add)%mod;
                            dp_next[nt][nc][no]=(dp_next[nt][nc][no]+val)%mod;
                         }
                    }
                }
            }
            dp_curr.swap(dp_next);
        }

        ll ans=0;
        for(int c=0;c<=C;c++){
            int pc=__builtin_popcount(c);
            for(int o=0;o<=O;o++){
                if(o+pc!=k)continue;

                ll coeff=dp_curr[T][c][o];
                if(!coeff)continue;

                ll add=coeff*fact[T]%mod;
                ans=(ans+add)%mod;
            }
        }
        return (int)ans;
    }
};

// Time Complexity : O(N*(M^3)*K) => O(N^5);
// Space Complexity: O((M^2)*K) => O(N^3);