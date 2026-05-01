// Problem Link: https://leetcode.com/problems/rotate-function/description/?envType=daily-question&envId=2026-05-01

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int fk=0, n=nums.size();
        int tt=accumulate(nums.begin(),nums.end(),0);

        for(int i=0;i<n;i++) fk+=i*nums[i];

        int ans=fk;
        for(int i=n-1;i>0;i--){
            fk+=tt-n*nums[i];
            ans=max(ans,fk);
        }
        return ans;
    }
};

// Time Complexity : O(3*N) => O(N);
// Space Complexity: O(1);