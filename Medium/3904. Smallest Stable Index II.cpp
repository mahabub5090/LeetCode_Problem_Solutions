// Problem Link: https://leetcode.com/problems/smallest-stable-index-ii/description/?envType=daily-question&envId=2026-09-05

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        stack<int> minStack;
        int n=nums.size();

        minStack.push(nums[n-1]);
        for(int i=n-2;i>=0;i--){
            minStack.push(min(nums[i], minStack.top()));
        }   

        int maxScore=0;
        for(int i=0;i<n;i++){
            maxScore=max(maxScore,nums[i]);

            if(maxScore-minStack.top()<=k) return i;

            minStack.pop();
        }
        return -1;
    }
};

// Time Complexity : O(N) + O(N) => O(N);
// Space Complexity: O(N);