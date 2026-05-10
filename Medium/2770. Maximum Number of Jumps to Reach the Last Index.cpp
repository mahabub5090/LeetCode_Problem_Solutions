// Problem Link: https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/description/?envType=daily-question&envId=2026-05-10

// class Solution {
// public:
//     unordered_map<int,int> memo;

//     int backtrack(int i,auto &nums,int target){
//         int n=nums.size();
//         if(i==n-1) return 0;
//         if(memo.count(i)) return memo[i];
    
//         int currMax=-1;
//         for(int j=i+1;j<n;j++){
//             if(abs(nums[i]-nums[j])>target) continue;

//             int curr=backtrack(j,nums,target);
//             if(curr!=-1) currMax=max(currMax,curr+1);
//         }
//         return memo[i]=currMax;
//     }

//     int maximumJumps(vector<int>& nums, int target) {
//         int n=nums.size();
//         int ans=backtrack(0,nums,target);
//         return ans;
//     }
// };

// // Time Complexity : O(N^2);
// // Space Complexity: O(N);

// Way: 2 =>

class Solution {
public:
    int ans=-1;
    unordered_map<int,int> memo;

    void backtrack(int i,int cnt,auto &nums,int target){
        int n=nums.size();
        if(i==n-1) {
            ans=max(ans,cnt);
            return;
        }

        if(memo.count(i) && memo[i]>=cnt) return;
        memo[i]=cnt;

        for(int j=i+1;j<n;j++){
            if(abs(nums[i]-nums[j])<=target) backtrack(j,cnt+1,nums,target);            
        }
    }

    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        backtrack(0,0,nums,target);
        return ans;
    }
};

// Time Complexity : O(N^2);
// Space Complexity: O(N);