// Problem Link: https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/?envType=daily-question&envId=2025-09-05

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int ans=1;
        while(1){
            long long x=num1-(1ll)*ans*num2;
            if(x<ans)return -1;
            if(ans>=__builtin_popcountll(x))return ans;
            ans++;
        }
        return -1;
    }
};

// Time Complexity : O(log(num1)) => O(logN);
// Space Complexity: O(1);