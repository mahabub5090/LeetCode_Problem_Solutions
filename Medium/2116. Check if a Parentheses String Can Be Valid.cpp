// Problem Link: https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/description/?envType=daily-question&envId=2025-01-12

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.size();
        if (n%2)return 0;
        int cnt=0,store=0;
        for (int i=0;i<n;i++) {
            if(locked[i]=='0')store++;
            else{
                if(s[i]=='(')cnt++;
                else cnt--;
            }
            if(cnt+store<0)return 0;
        }
        cnt=0;
        store=0;
        for (int i=n-1;i>=0;i--) {
            if(locked[i]=='0')store++;
            else{
                if(s[i]==')')cnt++;
                else cnt--;
            }
            if(cnt+store<0)return 0;
        }
        return 1;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(1);