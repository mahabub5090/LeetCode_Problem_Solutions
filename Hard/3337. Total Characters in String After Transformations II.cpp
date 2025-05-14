// Problem Link: https://leetcode.com/problems/total-characters-in-string-after-transformations-ii/description/?envType=daily-question&envId=2025-05-14

 class Mat{
public:
    vector<vector<long long>>m;
    long long mod=1e9+7;

    Mat(){
        m.assign(26,vector<long long>(26,0));
    }
    static Mat identity() {
        Mat I;
        for(int i=0;i<26;i++)I.m[i][i]=1;
        return I;
    }
    Mat operator*(const Mat &other)const{
        Mat res;
        for(int i=0;i<26;i++){
            for(int k=0;k<26;k++) {
                if(m[i][k]==0)continue;
                for(int j=0;j<26;j++) {
                    res.m[i][j]=(res.m[i][j]+m[i][k]*other.m[k][j])%mod;
                }
            }
        }
        return res;
    }
    Mat pow(long long exp)const{
        Mat base=*this;
        Mat res=identity();
        while(exp) {
            if(exp&1)res=res*base;
            base=base*base;
            exp>>=1;
        }
        return res;
    }
};
class Solution{
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        long long mod=1e9+7;

        Mat T;
        for(int i=0;i<26;i++) {
            for(int j=1;j<=nums[i];j++) {
                int to=(i+j)%26;
                T.m[to][i]=(T.m[to][i]+1)%mod;
            }
        }
        
        vector<long long>freq(26,0);
        for(auto &c:s)freq[c-'a']++;

        Mat Tt=T.pow(t);

        vector<long long>result(26,0);
        for(int i=0;i<26;i++) {
            for(int j=0;j<26;j++) {
                result[i]=(result[i]+Tt.m[i][j]*freq[j])%mod;
            }
        }

        long long ans=0;
        for(int i=0;i<26;i++)ans=(ans+result[i])%mod;

        return ans;
    }
};

// Time Complexity : O((26^3)*log(t))+O(26^2) => O(17576*log(t)) => O(logN)
// Space Complexity: O(26^2)+O(26+26) => O(1);