// Problem Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/?envType=daily-question&envId=2026-05-15

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();

        int l=0, r=n-1;
        while(l<r){
            int mid=l+(r-l)/2;

            if(nums[mid]<nums[r]) r=mid;
            else l=mid+1;
        }
        return nums[l];
    }
};

// Time Complexity : O(logN);
// Space Complexity: O(1);