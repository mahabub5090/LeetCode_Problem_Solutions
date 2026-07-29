// Problem Link: https://leetcode.com/problems/smallest-palindromic-rearrangement-ii/description/?envType=daily-question&envId=2026-07-29

class Solution {
public:
    using ll = long long;

    ll comb(ll n,ll m,ll k){
        ll mul=1;
        m=min(m,n-m);

        for(int i=1;i<=m;i++){
            mul*=n-i+1;
            mul/=i;

            if(mul>k) return k+1;   
        }
        return mul;
    }
    ll permutations(int rem,auto &cnt,int k){
        ll ways=1;
        for(int i=0;i<26;i++){
            if(cnt[i]==0) continue;

            ways*=comb(rem,cnt[i],k);
            if(ways>k) break;
            rem-=cnt[i];
        }
        return ways;
    }

    string smallestPalindrome(string s, int k) {
        int n=s.size();
        vector<int> cnt(26,0);
        for(int i=0;i<n/2;i++) cnt[s[i]-'a']++;

        string left="";
        ll si=1;

        for(int i=0;i<n/2;i++){
            for(int j=0;j<26;j++){
                if(cnt[j]==0) continue;

                cnt[j]-=1;

                ll ways=permutations(n/2-i-1,cnt,k);
                if(si+ways>k){
                    left+='a'+j;
                    break;
                }

                cnt[j]++;
                si+=ways;
            }
        }

        if(left.size()<n/2) return "";

        string mid=n%2?string(1,s[n/2]):"";
        string right=left;
        reverse(right.begin(),right.end());

        return left+mid+right;
    }
};

// Time Complexity : O(N/2) + O((N/2)*26*(26*(N/2))) + O(N/2) => O(N) + O(N*26*26*N) + O(N) => O(N^2);
// Space Complexity: O(26) + O(N) => O(N);