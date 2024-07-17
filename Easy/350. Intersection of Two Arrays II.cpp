// Problem Link: https://leetcode.com/problems/intersection-of-two-arrays-ii/description/?envType=daily-question&envId=2024-07-02

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_map<int,int>mp; for(auto &c:nums1)mp[c]++;
        for(auto &c:nums2){
            if(mp[c])mp[c]--,ans.push_back(c);
        }
        return ans;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(2*N) => O(N);