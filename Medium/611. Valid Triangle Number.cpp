// Problem Link: https://leetcode.com/problems/valid-triangle-number/solutions/127784/valid-triangle-number/?envType=daily-question&envId=Invalid%20Date

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int cnt=0;
        sort(nums.begin(),nums.end());
        if(nums.size()<3)return 0;
        for(int i=0;i<nums.size()-2;i++) {
            if(nums[i]==0)continue;
            long long k=i+2;
            for(int j=i+1;j<nums.size()-1;j++) {
                while(k<nums.size() && nums[i]+nums[j]>nums[k]){k++;}
                cnt+=k-j-1;
            }
        }
        return cnt;
    }
};

// Time Complexity : O((N^2)logN);
// Time Complexity : O(1);

