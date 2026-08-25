// Problem Link: https://leetcode.com/problems/smallest-missing-multiple-of-k/description/?envType=daily-question&envId=2026-08-25

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(),nums.end());
        int ans=k;
        while(true){
            if(st.count(ans)==0) return ans;
            ans+=k;
        }
        return ans;
    }
};

// Time Complexity : O(N) + O(M) => O(N);
// Space Complexity: O(N);
// M = smallest positive multiple of 'K';
// N = nums.size(), M <= N;