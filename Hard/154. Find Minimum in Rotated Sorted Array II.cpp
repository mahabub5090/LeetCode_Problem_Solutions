// Problem Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/?envType=daily-question&envId=2026-05-16

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        
        int l=0, r=n-1;
        while(l<r){
            int mid=l+(r-l)/2;

            if(nums[mid]<nums[r]) r=mid;
            else if(nums[mid]>nums[r]) l=mid+1;
            else r--;
        }
        return nums[l];
    }
};

// Time Complexity : O(N); // O(logN) for average/best case;
// Space Complexity: O(1);