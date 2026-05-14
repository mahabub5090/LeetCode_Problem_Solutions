// Problem Link: https://leetcode.com/problems/check-if-array-is-good/description/?envType=daily-question&envId=2026-05-14

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size()-1;
        unordered_map<int,int> mp;
        for(auto &c:nums) mp[c]++;
        for(int i=1;i<n;i++){
            if(mp[i]==1)continue;
            return 0;
        }
        return mp[n]==2;
    }
};

// Time Complexity : O(N) + O(N) => O(N);
// Space Complexity: O(N);