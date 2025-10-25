// Problem Link: https://leetcode.com/problems/calculate-money-in-leetcode-bank/description/?envType=daily-question&envId=2025-10-25

class Solution {
public:
    int totalMoney(int n) {
        int week=n/7,val=7*(7+1)/2;
        int add=(week-1)*week/2;
        int ans=(week*val)+(add*7);
        for(int i=0;i<n%7;i++)ans+=week+i+1; 
        return ans;
    }
};

// Time Complexity : O(1);
// Space Complexity: O(1);