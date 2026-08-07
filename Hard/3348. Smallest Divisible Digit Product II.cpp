// Problem Link: https://leetcode.com/problems/smallest-divisible-digit-product-ii/description/?envType=daily-question&envId=2026-08-07

class Solution {
public:
    using ll = long long;
    
    string smallestNumber(string num, long long t) {
        ll temp=t;
        for(int i=2;i<10;i++){
            while(temp && temp%i==0) temp/=i;
            if(temp==1) break;
        }
        if(temp>1) return "-1";

        int n=num.size();
        vector<ll> rem(n+1);
        rem[0]=t;

        int index=n-1;
        for(int i=0;i<n;i++){
            if(num[i]=='0'){
                index=i;
                break;
            }
            rem[i+1]=rem[i]/__gcd(rem[i],(ll) num[i]-'0');
        }
        if(rem[n]==1) return num;

        for(int i=index;i>=0;i--){
            while(++num[i]<='9'){
                ll currT=rem[i]/__gcd(rem[i],(ll) num[i]-'0');

                int k=9;
                for(int j=n-1;j>i;j--){
                    while(currT%k) k--;
                    currT/=k;
                    num[j]='0'+k;
                }

                if(currT==1) return num;
            }
        }

        string ans="";
        for(int i=9;i>1;i--){
            while(t%i==0) ans+='0'+i, t/=i;
        }

        int extra=max(n+1-(int)ans.size(), 0);
        ans+=string(extra,'1');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// Time Complexity : O(logT) + O(NlogT) + O(NlogT) + O(logT) + O(N) => O(NlogT);
// Space Complexity: O(N) + O(N) => O(N);
// here, suffix construction is amortized O(NlogT);