// Problem Link: https://leetcode.com/problems/kth-smallest-amount-with-single-denomination-combination/description/?envType=daily-question&envId=2026-08-21

class Solution {
public:
    using ll = long long;

    ll get(ll mid, auto &bitCnt, auto &lcm){
        ll cnt=0, m=bitCnt.size();
        for(int i=1;i<m;i++){
            if(lcm[i]>mid) continue;

            if(bitCnt[i]&1) cnt+=mid/lcm[i];
            else cnt-=mid/lcm[i];
        }
        return cnt;
    }


    long long findKthSmallest(vector<int>& coins, int k) {
        int n=coins.size(), m=(1<<n);
        sort(coins.begin(),coins.end());
        vector<ll> bitCnt(m);
        vector<ll> lcm(m);
        ll l=k, r=1ll*coins[0]*k+1;

        for(int i=0;i<m;i++){
            ll currLcm=1;
            for(int j=0;j<n;j++){
                if((i>>j)%2==0) continue;

                ll temp=currLcm/gcd(currLcm,coins[j]);

                if(temp<=r/coins[j]) currLcm=temp*coins[j];
                else{
                    currLcm=r+1;
                    break;
                }

                bitCnt[i]++;
            }
            lcm[i]=currLcm;
        }

        while(l<r){
            ll mid=l+(r-l)/2;

            if(get(mid,bitCnt,lcm)<k) l=mid+1;
            else r=mid;
        }   
        return l;
    }
};

// Time Complexity : O(M*N) + O(log(min(coins)*K)*M) => O(M*log(K*min(coins)));
// Space Complexity: O(M) + O(M) => O(M);
// M = 2^N && N = coins.size();