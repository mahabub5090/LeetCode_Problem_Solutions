// Problem Link: https://leetcode.com/problems/find-the-count-of-good-integers/description/?envType=daily-question&envId=2025-04-12

class Solution {
long long countGoodIntegers(int n, int k) {
        public:
        set<string>dict;
        int base=pow(10,(n-1)/2);
        int skip=n%2;

        for(int i=base;i<base*10;i++){
            string s=to_string(i);
            s+=string(s.rbegin()+skip,s.rend());

            long long pal=stoll(s);

            if(pal%k==0){
                sort(s.begin(),s.end());
                dict.insert(s);
            }
        }

        vector<long long>fact(n+1,1);
        long long ans=0;
        for(int i=1;i<=n;i++){
            fact[i]=fact[i-1]*i;
        }

        for(auto &s:dict){
            vector<int>cnt(10,0);
            for(auto &c:s)cnt[c-'0']++;

            long long tt=(n-cnt[0])*fact[n-1];
            for(auto &c:cnt)tt/=fact[c];
            ans+=tt;
        }

        return ans;
    }
};

// Time Complexity : O(nlogn*(10^k)) => O((N^2)logN);
// Space Complexity: O(n*(10^k) => O(N^2);
// n,k is the given parameter of "countGoodIntegers()" function;