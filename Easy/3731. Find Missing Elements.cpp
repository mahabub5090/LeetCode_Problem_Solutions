// Problem Link: https://leetcode.com/problems/find-missing-elements/description/?envType=daily-question&envId=2026-08-04

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn=INT_MAX, mx=INT_MIN;
        unordered_set<int> st;
        for(auto &c:nums) mn=min(mn,c), mx=max(mx,c), st.insert(c);

        vector<int> ans;
        for(int i=mn;i<=mx;i++){
            if(st.count(i)==0) ans.push_back(i);
        }
        return ans;
    }
};

// Time Complexity : O(N) + O(M);
// Space Complexity: O(N) + O(M-N);
// M = max(nums[i]) - min(nums[i]);