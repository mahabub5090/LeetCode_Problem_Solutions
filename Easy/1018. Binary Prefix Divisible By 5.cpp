// Problem Link: https://leetcode.com/problems/binary-prefix-divisible-by-5/description/?envType=daily-question&envId=2025-11-24

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n=nums.size();
        vector<bool>ans(n);
        int num=0;
        for(int i=0;i<n;i++){
            num<<=1;
            num+=nums[i];
            num%=5ll;
            ans[i]=num==0;
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N); // for store answers;