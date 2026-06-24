// Problem Link: https://leetcode.com/problems/number-of-zigzag-arrays-ii/description/?envType=daily-question&envId=2026-06-24

class Solution {
public:
    int mod=1e9+7;
    using ll = long long;
    using Matrix = vector<vector<ll>>;

    Matrix multiply(auto &a,auto &b){
        int n=a.size(), m=b[0].size();
        Matrix result(n, vector<ll>(m,0));

        for(int i=0;i<n;i++){
            for(int k=0;k<a[0].size();k++){
                ll r=a[i][k];
                if(r==0) continue;
                for(int j=0;j<m;j++){
                    result[i][j]=(result[i][j]+r*b[k][j])%mod;
                }
            }
        }
        return result;
    }
    Matrix matrixPow(auto &base, int exp){
        int n=base.size();
        Matrix result(n, vector<ll>(n,0));
        for(int i=0;i<n;i++) result[i][i]=1;

        while(exp){
            if(exp%2) result=multiply(result,base);
            base=multiply(base,base);
            exp/=2;
        }
        return result;
    }


    int zigZagArrays(int n, int l, int r) {
        int m=r-l+1;
        if(n==1) return m;

        int len=2*m;
        Matrix T(len, vector<ll>(len,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<i;j++) T[i][j+m]=1;
            for(int j=i+1;j<m;j++) T[i+m][j]=1;
        }

        T=matrixPow(T,n-1);

        ll ans=0;
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                ans=(ans+T[i][j])%mod;
            }
        }
        return ans;
    }
};

// Time Complexity : O(len*len) + O(logN*(len*len*len)) + O(len*len) => O((len^3)*logN) => O((M^3)logN);
// Space Complexity: O(len*len) + O(len*len) => O(len^2) => O(M^2);
// len = 2*M and M = r-l+1;