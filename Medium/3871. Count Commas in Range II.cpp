// Problem Link: https://leetcode.com/problems/count-commas-in-range-ii/description/?envType=daily-question&envId=2026-09-09

class Solution {
public:
    long long countCommas(long long n) {
        if(n<1e3) return 0;
        long long ans=0, i=1;
        while(pow(1e3,i)<=n){
            ans+=(pow(1e3,i)-pow(1e3,i-1))*(i-1);
            i++;
        }
        ans+=(n-pow(1e3,i-1)+1)*(i-1);
        return ans;
    }
};

// Time complexity : O(logN);
// Space Complexity: O(1);