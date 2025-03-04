// Problem Link: https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/description/?envType=daily-question&envId=2025-03-04

// class Solution {
// public:
//     int backtrack(int i,int sum,int n){
//         if(sum==n)return 1;
//         if(sum>n || pow(3,i)>n)return 0;
//         if(backtrack(i+1,sum+pow(3,i),n))return 1;
//         return backtrack(i+1,sum,n);
//     }
//     bool checkPowersOfThree(int n) {
//         return backtrack(0,0,n);
//     }
// };

// Time Complexity : O(2^((log3)N)) => O(N);
// Space Complexity: O(1);

// way: 2 =>

class Solution {
public:
    bool checkPowersOfThree(int n) {
        int i=0;
        while(pow(3,i+1)<=n)i++;
        while(i>=0){
            int pw=pow(3,i);
            if(pw<=n)n-=pw;
            i--;
        }
        return n==0;
    }
};

// Time Complexity : O((log3)N) => O(logN);
// Space Complexity: O(1);