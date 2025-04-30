// Problem Link: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/description/?envType=daily-question&envId=2025-04-30

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(auto &c:nums){
            int cnt=0;
            while(c)cnt++,c/=10;
            ans+=cnt%2==0;
        }
        return ans;
    }
};

// Time complexity : O(NlogN);
// Space Complexity: O(1);