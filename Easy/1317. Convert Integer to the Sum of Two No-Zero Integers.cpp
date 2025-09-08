// Problem Link: https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/description/?envType=daily-question&envId=2025-09-08

class Solution {
public:
    int hasZero(int n){
        while(n){
            if(n%10==0)return 1;
            n/=10;
        }
        return 0;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<n;i++){
            if(hasZero(i)==0 && hasZero(n-i)==0)return {i,n-i};
        }   
        return {};
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(1);
