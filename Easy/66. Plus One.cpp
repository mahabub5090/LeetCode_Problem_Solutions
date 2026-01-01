// Problem Link: https://leetcode.com/problems/plus-one/description/?envType=daily-question&envId=2026-01-01

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int curr=1;

        for(int i=n-1;i>=0;i--){
            curr+=digits[i];
            digits[i]=curr%10;
            curr=max(0,curr-9);
        }

        if(curr)digits.insert(digits.begin(),curr);
        return digits;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(1)