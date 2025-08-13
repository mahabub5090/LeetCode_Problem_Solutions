// Problem Link: https://leetcode.com/problems/power-of-three/description/?envType=daily-question&envId=2025-08-13

// class Solution {
// public:
//     bool isPowerOfThree(int n) {
//         for(int i=0;pow(3,i)<=INT_MAX;i++){
//             if(pow(3,i)==n)return 1;
//         }
//         return 0;
//     }
// };

// // Time Complexity : O(20) => O(1);
// // Space Complexity: O(1);

// Way: 2 =>

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n>0 && (int)pow(3,19)%n==0;
    }
};

// Time Complexity : O(1);
// Space Complexity: O(1);