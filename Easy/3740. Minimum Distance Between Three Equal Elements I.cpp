// Problem Link: https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/description/?envType=daily-question&envId=2026-04-10

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans=INT_MAX,n=nums.size();
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]==nums[j] && nums[j]==nums[k]){
                        ans=min(ans,j-i+k-j+k-i);
                    }
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};

// Time Complexity : O(N^3);
// Space Complexity: O(1);