// Problem Link: https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/description/?envType=daily-question&envId=2025-05-27

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num=0,num2=0;
        for(int i=1;i<=n;i++)i%m?num+=i:num2+=i;
        return num-num2;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);