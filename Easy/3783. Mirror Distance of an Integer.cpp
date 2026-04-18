// Problem Link: https://leetcode.com/problems/mirror-distance-of-an-integer/description/?envType=daily-question&envId=2026-04-18

class Solution {
public:
    int reverse(int num){
        int ans=0;
        while(num){
            ans=(ans*10)+num%10;
            num/=10;
        }
        return ans;
    }

    int mirrorDistance(int n) {
        return abs(n-reverse(n));
    }
};

// Time Complexity : O(9) => O(1);
// Space Complexity: O(1);
// length of num <= 9;