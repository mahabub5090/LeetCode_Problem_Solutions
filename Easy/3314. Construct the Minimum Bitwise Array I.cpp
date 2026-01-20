// Problem Link: https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/description/?envType=daily-question&envId=2026-01-20

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for(auto &c:nums){
            int temp=c;

            for(int i=1;i<c;i++){
                if((i|(i+1))==c){
                    c=i;
                    break;
                }
            }

            if(c==temp)c=-1;
        }
        return nums;
    }
};

// Time Complexity : O(N*nums[i]) => O(N^2);
// Space Complexity: O(1);
