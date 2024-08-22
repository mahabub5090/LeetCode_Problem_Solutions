// Problem Link: https://leetcode.com/problems/number-complement/description/?envType=daily-question&envId=2024-08-22

class Solution {
public:
    int findComplement(int num) {
        int ans=0;
        int i=0;
        while(num){
            if((num&1)==0)ans+=1<<i;
            i+=1;
            num>>=1;
        }
        return ans;
    }
};

// Time Complexity : O(logN);
// Space Complexity: O(1);