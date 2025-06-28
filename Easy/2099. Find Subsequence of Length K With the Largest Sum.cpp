// Problem Link: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/description/?envType=daily-question&envId=2025-06-28

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int>copy=nums;
        sort(copy.rbegin(),copy.rend());
        unordered_map<int,int>mp;
        for(int i=0;i<k;i++)mp[copy[i]]++;
        vector<int>ans;
        for(auto &c:nums){
            if(mp[c]){
                ans.push_back(c);
                mp[c]--;
            }
        }
        return ans;
    }
};

// Time Complexity : O(NlogN + 2*N) => O(NlogN);
// Space Complexity: O(3*N) => O(N);