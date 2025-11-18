// Problem Link: https://leetcode.com/problems/1-bit-and-2-bit-characters/description/?envType=daily-question&envId=2025-11-18

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size();
        for(int i=0;i<n-1;i++){
            if(bits[i]==1)i+=1;
            if(i==n-1)return 0;
        }
        return 1;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);