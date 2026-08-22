// Problem Link: https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/description/?envType=daily-question&envId=2026-08-22

class Solution {
public:
    bool checkDivisibility(int n) {
        int temp=n, sum=0, product=1;
        
        while(temp){
            int digit=temp%10;
            temp/=10;

            sum+=digit, product*=digit;
        }
        return n%(sum+product)==0;
    }
};

// Time Complexity : O(logN);
// Space Complexity: O(1);