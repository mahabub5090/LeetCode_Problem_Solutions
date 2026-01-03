// Problem Link: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/description/?envType=daily-question&envId=2026-01-03

class Solution {
public:
    int numOfWays(int n) {
        long long x=6,y=6,mod=1e9+7;
        for(int i=1;i<n;i++){
            long long nx=(3*x+2*y)%mod;
            long long ny=(2*x+2*y)%mod;
            x=nx;
            y=ny;
        }
        return (x+y)%mod;;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);