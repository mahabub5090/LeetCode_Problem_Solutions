// Problem Link: https://leetcode.com/problems/count-the-number-of-ideal-arrays/description/?envType=daily-question&envId=2025-04-22

const int maxn=1e4+10,maxp=15,mod=1e9+7;
int C[maxn+maxp][maxp+1];
vector<int>ps[maxn];
int sieve[maxn];

class Solution {
public:
    Solution(){
        if(C[0][0])return;

        for(int i=2;i<maxn;i++){
            if(sieve[i]==0){
                for(int j=i;j<maxn;j+=i)sieve[j]=i;
            }
        }
        for(int i=2;i<maxn;i++){
            int c=i;
            while(c>1){
                int p=sieve[c];
                int cnt=0;
                while(c%p==0)c/=p,cnt++;
                ps[i].push_back(cnt);
            }
        }
    
        C[0][0]=1;
        for(int i=1;i<maxn+maxp;i++){
            C[i][0]=1;
            for(int j=1;j<=min(i,maxp);j++){
                C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
            }
        }
    }

    int idealArrays(int n, int maxValue) {
        long long ans=0;
        for(int i=1;i<=maxValue;i++){
            long long mul=1;
            for(auto &c:ps[i])mul*=C[n+c-1][c],mul%=mod;
            ans+=mul;
            ans%=mod;
        }
        return ans;
    }
};
 
// Time Complexity : O((maxn+maxp)*log(maxn+maxp)) => O(NlogN);
// Space Complexity: O((maxn+maxp)*log(maxn+maxp)) => O(NlogN);