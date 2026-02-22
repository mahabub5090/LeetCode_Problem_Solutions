// Problem Link: https://leetcode.com/problems/binary-gap/description/?envType=daily-question&envId=2026-02-22

class Solution {
public:
    int binaryGap(int n) {
        int prev=-1,ans=0;
        while(n){
            if(n&1){
                if(prev==-1) prev=0;
                else{
                    ans=max(ans,prev+1);
                    prev=0;
                }
            }
            else if(prev!=-1) prev++;
            n>>=1;
        }
        return ans;
    }
};

// Time Complexity : O(logN); // O(32);
// Space Complexity: O(1);