// Problem Link: https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/description/?envType=daily-question&envId=2026-07-07

class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x=0, mul=1, sum=0;
        while(n){
            int rem=n%10;
            n/=10;
            if(rem==0) continue;
            
            x+=rem*mul;
            mul*=10;
            sum+=rem;
        }
        return x*sum;
    }
};

// Time Complexity : O(logN);
// Space Complexity: O(1);