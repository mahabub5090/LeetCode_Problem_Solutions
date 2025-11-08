// Problem Link: https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/description/?envType=daily-question&envId=2025-11-08

class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n==0)return n;

        int k=0,curr=1;
        while(2*curr<=n)curr*=2,k++;

        return (1<<(k+1))-1-minimumOneBitOperations(n^curr);
    }
};

// Time Complexity : O((log^2)N) => O(logN);
// Space Complexity: O((log^2)N) => O(logN);