// Problem Link: https://leetcode.com/problems/container-with-most-water/description/?envType=daily-question&envId=2025-10-04

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1,ans=min(height[i],height[j])*j;
        while(i<j){
            if(height[i]<height[j])i++;
            else j--;
            ans=max(ans,min(height[i],height[j])*(j-i));
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);