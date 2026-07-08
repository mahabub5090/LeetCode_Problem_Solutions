// Problem Link: https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-ii/description/?envType=daily-question&envId=2026-07-08

class Solution {
public:
    using ll = long long;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size(), mod=1e9+7;

        vector<ll> pow10(n+1,1);
        for(int i=1;i<=n;i++) pow10[i]=(pow10[i-1]*10)%mod;

        vector<int> nonZero(n+1,0);
        vector<ll> val(n+1,0), totalSum(n+1,0);

        int cnt=0;
        for(int i=0;i<n;i++){
            int digit=s[i]-'0';

            if(digit){
                cnt++;
                val[cnt]=(val[cnt-1]*10+digit)%mod;
                totalSum[cnt]=totalSum[cnt-1]+digit;
            }
            nonZero[i+1]=cnt;
        }


        vector<int> ans;
        for(auto &c:queries){
            int l=nonZero[c[0]], r=nonZero[c[1]+1];

            if(l==r) ans.push_back(0);
            else{
                int len=r-l;

                ll num=((val[r]-val[l]*pow10[len])%mod+mod)%mod;
                ll sum=totalSum[r]-totalSum[l];

                ans.push_back((num*sum)%mod);
            }
        }
        return ans;
    }
};

// Time Complexity : O(N) + O(N) + O(Q) => O(N+Q) => O(N);
// Space Complexity: O(N) + O(N) + O(N) + O(N) + O(Q) => O(N+Q) => O(N);
// N = s.size(), Q = queries.size() and 1 <= N,Q <= 1e5;