// Problem Link: https://leetcode.com/problems/gcd-of-odd-and-even-sums/description/?envType=daily-question&envId=2026-07-15

// class Solution {
// public:
//     int gcdOfOddEvenSums(int n) {
//         int oddSum=n*n;
//         int evenSum=n*(n+1);
//         // cout<<evenSum<<" "<<oddSum;
//         return __gcd(oddSum,evenSum);
//     }
// };

// Time Complexity : O(logN);
// Space Complexity: O(1);


// Way: 2 =>

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        /*
                __gcd(n*n,n*(n+1));
            =>n*__gcd(n,n+1);
            =>n*1 ; // __gcd(n,n+1)=1; because, both are coprime.
        */
        return n;
    }
};

// Time Complexity : O(1);
// Space Complexity: O(1);