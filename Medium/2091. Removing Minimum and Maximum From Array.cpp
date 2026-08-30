// Problem Link: https://leetcode.com/problems/removing-minimum-and-maximum-from-array/description/?envType=daily-question&envId=2026-08-30

// Way: 1 (Also work If, the Elements are not-distinct) => 

// class Solution {
// public:
//     int dist(int i, int j, int dir, int target, auto &nums){
//         int dist=0;
//         if(dir==1) while(i<=j && nums[i]!=target) i++, dist++;
//         else while(j>=i && nums[j]!=target) j--, dist++;
//         return dist+1;
//     }

//     int minimumDeletions(vector<int>& nums) {
//         int minVal=INT_MAX, maxVal=INT_MIN;
//         for(auto &c:nums) minVal=min(minVal,c), maxVal=max(maxVal,c);

//         int n=nums.size(), ans=n;
//         int i=0, j=n-1, one, two;

//         // 1st Case: Remove minVal from left and maxVal from right;
//         one=dist(i,j,1,minVal,nums);
//         two=dist(i,j,-1,maxVal,nums);
//         ans=min(ans, one+two);

//         // 2nd Case: vice-versa of 1st Case;
//         one=dist(i,j,-1,minVal,nums);
//         two=dist(i,j,1,maxVal,nums);
//         ans=min(ans, one+two);

//         // 3rd Case: Remove min-max from left;
//         one=dist(i,j,1,minVal,nums);
//         two=dist(i,j,1,maxVal,nums);
//         ans=min(ans, (one+two)-min(one,two));

//         // 4rd Case: vice-versa of 3rd Case;
//         one=dist(i,j,-1,minVal,nums);
//         two=dist(i,j,-1,maxVal,nums);
//         ans=min(ans, (one+two)-min(one,two));

//         return ans;
//     }
// };

// // Time Complexity : O(5*N) => O(N);
// // Space Complexity: O(1);


// Way: 2 (Optimized For distinct elements) =>

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minVal=INT_MAX, maxVal=INT_MIN;
        int mini, maxi, n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<minVal) minVal=nums[i], mini=i+1;
            if(nums[i]>maxVal) maxVal=nums[i], maxi=i+1;
        }

        int ans=n;

        // 1st Case: Remove minVal from left and maxVal from right;
        ans=min(ans, (mini + n-maxi+1));

        // 2nd Case: vice-versa of 1st Case;
        ans=min(ans, (maxi + n-mini+1));

        // 3rd Case: Remove min-max from left;
        ans=min(ans, (mini + maxi - min(mini, maxi)));

        // 4rd Case: vice-versa of 3rd Case;
        ans=min(ans, 1 + (n-mini + n-maxi - min(n-mini, n-maxi)));

        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);