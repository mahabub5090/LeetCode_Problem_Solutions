// Problem Link: https://leetcode.com/problems/smallest-integer-divisible-by-k/description/?envType=daily-question&envId=2025-11-25

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        long long num=0,mul=1;
        for(int i=0;i<k;i++){
            num+=mul;
            if(num%k==0)return ++i;
            mul*=10;
            mul%=k;
        }
        return -1;
    }
};

// Time Complexity : O(K) => O(N);
// Space Complexity: O(1);