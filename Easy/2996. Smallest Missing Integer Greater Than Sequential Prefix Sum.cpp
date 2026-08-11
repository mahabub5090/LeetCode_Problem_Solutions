// Problem Link: https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/description/?envType=daily-question&envId=2026-08-11

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int i=1, n=nums.size();
        int ans=nums[0];
        while(i<n && nums[i]==nums[i-1]+1) ans+=nums[i++];
        
        while(st.count(ans)) ans++;
        return ans;
    }
};

// Time Complexity : O(N) + O(N) + O(N) => O(N);
// Space Complexity: O(N);