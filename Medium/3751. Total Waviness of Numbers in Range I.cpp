// Problem Link: https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/description/?envType=daily-question&envId=2026-06-04

class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int i=num1;i<=num2;i++){
            string s=to_string(i);
            for(int i=1;i<s.size()-1;i++){
                int peak=(s[i-1]<s[i] && s[i]>s[i+1]);
                int valley=(s[i-1]>s[i] && s[i]<s[i+1]);
                ans+=(peak || valley);
            }
        }
        return ans;
    }
};

// Time Complexity : O((num2-num1)*log(num2)) => O(NlogN);
// Space Complexity: O(log(num2)) => O(logN);