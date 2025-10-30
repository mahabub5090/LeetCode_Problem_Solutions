// Problem Link: https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/description/?envType=daily-question&envId=2025-10-30

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans=target[0];
        for(int i=0;i<target.size()-1;i++){
            ans+=max(target[i+1]-target[i],0);
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);
