// Problem Link: https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/description/?envType=daily-question&envId=2026-01-22

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n=nums.size();
        int flag=is_sorted(nums.begin(),nums.end());
        while(flag==0){
            int mn=INT_MAX,index=-1;
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]+nums[i+1]<mn){
                    mn=nums[i]+nums[i+1];
                    index=i;
                }
            }

            nums[index]+=nums[index+1];

            for(int i=index+1;i<nums.size()-1;i++){
                nums[i]=nums[i+1];
            }
            nums.pop_back();

            flag=is_sorted(nums.begin(),nums.end());
        }
        return n-nums.size();
    }
};

// Time Complexity : O(N*N) => O(N^2);
// Space Complexity: O(1);