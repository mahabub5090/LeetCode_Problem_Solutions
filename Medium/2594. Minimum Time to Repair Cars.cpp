// Problem Link: https://leetcode.com/problems/minimum-time-to-repair-cars/description/?envType=daily-question&envId=2025-03-16

class Solution {
public:
    int possible(long long mid,auto &ranks,int cars){
        long long cnt=0;
        for(auto &c:ranks){
            cnt+=sqrt(mid/c);
        }
        return cnt>=cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long l=0,r=LLONG_MAX;

        while(l<=r){
            long long mid=l+(r-l)/2;
            if(possible(mid,ranks,cars))r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};

// Time Complexity : O(Nlog(1e18)) => O(NlogN);
// Space Complexity: O(1);