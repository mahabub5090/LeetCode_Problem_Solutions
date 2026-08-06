// Problem Link: https://leetcode.com/problems/smallest-divisible-digit-product-i/description/?envType=daily-question&envId=2026-08-06

class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            int temp=n, product=1;
            while(temp) product*=temp%10, temp/=10;
            if(product%t==0) return n;
            n++;
        }
        return 0;
    }
};

// Time Complexity : O(10 * logN) => O(10logN);
// Space Complexity: O(1);
// after adding upto 10, we will surely get a zero in 'n' and the product will become 0 and it divisible by all number.