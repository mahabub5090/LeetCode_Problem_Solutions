// Problem Link: https://leetcode.com/problems/find-the-original-typed-string-ii/description/?envType=daily-question&envId=2025-07-02https://leetcode.com/problems/find-the-original-typed-string-ii/description/?envType=daily-question&envId=2025-07-02

class Solution {
public:
    int possibleStringCount(string word, int k) {
        int n=word.size(),mod=1e9+7;
        vector<int>freq;
        int cnt=1;
        for(int i=0;i<n-1;i++){
            if(word[i]==word[i+1])cnt++;
            else freq.push_back(cnt),cnt=1;
        }
        freq.push_back(cnt);

        long long ans=1;
        for(auto &c:freq){
            ans*=c;
            ans%=mod;
        }
        if(freq.size()>=k)return ans;

        vector<int>f(k),g(k,1);
        f[0]=1;
        for(int i=0;i<freq.size();i++){
            vector<int>nf(k);
            for(int j=1;j<k;j++){
                nf[j]=g[j-1];
                if(j-freq[i]-1>=0){
                    nf[j]=(nf[j]-g[j-freq[i]-1])%mod;
                }
            }
            vector<int>ng(k);
            ng[0]=nf[0];
            for(int j=1;j<k;j++){
                ng[j]=(ng[j-1]+nf[j])%mod;
            }
            f=move(nf);
            g=move(ng);
        }
        return (ans-g[k-1]+mod)%mod;
    }
};

// Time Complexity : O(N + min(N,K)^2) => O(N); // Cause, maximam K <=2000;
// Space Complexity: O(N+K);