// Problem Link: https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/description/?envType=daily-question&envId=2026-03-13

class Solution {
public:
    using ll=long long;

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int maxTime=*max_element(workerTimes.begin(),workerTimes.end());
        ll ans=0;
        ll l=1,r=maxTime*(1ll*mountainHeight*(mountainHeight+1)/2);
        while(l<=r){
            ll mid=l+(r-l)/2;
            ll cnt=0;
            for(auto &c:workerTimes){
                ll work=mid/c;
                ll nth=(sqrt(8.0*work+1)-1)/2+1e-9;
                cnt+=nth;
            }

            if(cnt>=mountainHeight){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};

// Time Complexity : O(Nlog(M*(H^2))) => O(Nlog(N^3));
// Space Complexity: O(1);
// M = max(workerTimes), H = mountainHeight;