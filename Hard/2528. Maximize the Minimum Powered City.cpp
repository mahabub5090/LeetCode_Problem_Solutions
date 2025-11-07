// Problem Link: https://leetcode.com/problems/maximize-the-minimum-powered-city/description/?envType=daily-question&envId=2025-11-07

class Solution {
public:
    int check(long long val,auto &cnt,int r,int k){
        vector<long long>diff=cnt;
        long long sum=0,remaining=k,n=cnt.size()-1;

        for(int i=0;i<n;i++){
            sum+=diff[i];
            if(sum<val){
                long long add=val-sum;
                if(remaining<add)return 0;
                remaining-=add;
                int end=min((int)n,i+2*r+1);
                diff[end]-=add;
                sum+=add;
            }
        }
        return 1;
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        int n=stations.size();
        vector<long long>cnt(n+1,0);

        for(int i=0;i<n;i++){
            int left=max(0,i-r);
            int right=min(n,i+r+1);
            cnt[left]+=stations[i];
            cnt[right]-=stations[i];
        }

        long long mn=*min_element(stations.begin(),stations.end());
        long long tt=accumulate(stations.begin(),stations.end(),0ll)+k;
        long long ans=0;

        while(mn<=tt){
            long long mid=mn+(tt-mn)/2;

            if(check(mid,cnt,r,k)){
                ans=mid;
                mn=mid+1;
            }
            else tt=mid-1;
        }
        return ans;
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(N);