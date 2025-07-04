// Problem Link: https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/description/?envType=daily-question&envId=2025-07-04

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        k--;
        long shift=0;
        while(k){
            long len=1;
            while(2*len<=k)len*=2;
            if(operations[__lg(len)])shift++;
            k-=len;
        }
        return 'a'+shift%26;
    }
};

// Time Complexity : O(logK) => O(logN);
// Space Complexity: O(1);