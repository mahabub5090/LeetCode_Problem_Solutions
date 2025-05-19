// Problem Link: https://leetcode.com/problems/type-of-triangle/submissions/1638500622/?envType=daily-question&envId=2025-05-19

class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a=nums[0],b=nums[1],c=nums[2];

        if(a+b>c && a+c>b && b+c>a){
            if(a==b && b==c)return "equilateral";
            if(a==b || a==c || b==c)return "isosceles";
            return "scalene";
        }
        return "none";
    }
};

// Time Complexity : O(1);
// Space Complexity: O(1);