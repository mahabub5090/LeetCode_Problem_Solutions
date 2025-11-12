// Problem Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/description/?envType=daily-question&envId=2025-11-12

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int num=0,gcd=0;
        for(auto &c:nums)gcd=__gcd(gcd,c);
        if(gcd>1)return -1;
        int cnt=count(nums.begin(),nums.end(),1);
        if(cnt>1)return n-cnt;

        int minLen=n;
        for(int i=0;i<n;i++){
            int g=0;
            for(int j=i;j<n;j++){
                g=__gcd(g,nums[j]);
                if(g==1){
                    minLen=min(minLen,j-i+1);
                    break;
                }
            }
        }
        return n+minLen-2;
    }
};

// Time Complexity : O((N^2) * logN) => O((N^2)logN);
// Space Complexity: O(1);