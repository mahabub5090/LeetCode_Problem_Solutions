// Problem Link: https://leetcode.com/problems/total-waviness-of-numbers-in-range-ii/description/?envType=daily-question&envId=2026-06-05

class Solution {
public:
    using ll=long long;
    ll memoCnt[16][11][11],memoSum[16][11][11];
    string s;
    int n;

    pair<ll,ll> dfs(int pos,int prev,int curr,int limit,int leading){
        if(pos==n) return {1,0};

        if(limit==0 && leading==0 && memoCnt[pos][prev+1][curr+1]!=-1){
            return {memoCnt[pos][prev+1][curr+1],memoSum[pos][prev+1][curr+1]};
        }

        ll cnt=0,sum=0,up=limit?s[pos]-'0':9;

        for(int digit=0;digit<=up;digit++){
            int newLimit=limit && (digit==up);
            int newLeading=leading && (digit==0);
            int newPrev=curr;
            int newCurr=newLeading?-1:digit;

            auto [subCnt,subSum]=dfs(pos+1,newPrev,newCurr,newLimit,newLeading);

            if(newLeading==0 && prev!=-1 && curr!=-1){
                if((prev<curr && curr>digit) || (prev>curr && curr<digit)) sum+=subCnt;
            }

            cnt+=subCnt;
            sum+=subSum;
        }

        if(limit==0 && leading==0){
            memoCnt[pos][prev+1][curr+1]=cnt;
            memoSum[pos][prev+1][curr+1]=sum;
        }
        return {cnt,sum};
    }
    ll solve(ll num){
        if(num<100) return 0;

        s=to_string(num);
        n=s.size();

        memset(memoCnt,-1,sizeof(memoCnt));
        memset(memoSum,-1,sizeof(memoSum));

        auto [_,tt]=dfs(0,-1,-1,1,1);
        return tt;
    }
    

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2)-solve(num1-1);
    }
};

// Time Complexity : O(N*(D^2)*D) => O(N*(D^3));
// Space Complexity: O(N*(D^2)) + O(N) => O(N*(D^2));
// N is the maximam number of digit in num2, D is the base of number system; Here, N<=16, D==10;