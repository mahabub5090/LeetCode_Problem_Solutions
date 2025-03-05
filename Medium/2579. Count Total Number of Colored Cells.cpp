// Problem Link: https://leetcode.com/problems/count-total-number-of-colored-cells/description/?envType=daily-question&envId=2025-03-05

// class Solution {
// public:
//     long long coloredCells(int n) {
//         long long ans=1;
//         for(int i=1;i<n;i++)ans+=(4*i);
//         return ans;
//     }
// };

// Time Complexity : O(N);
// Space Complexity: O(1);

// Way: 2 =>

class Solution {
public:
    long long coloredCells(int n) {
        return 1+(long long)n*(n-1)*2;
    }
};

// Time Complexity : O(1);
// Space Complexity: O(1);
    