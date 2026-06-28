// Problem Link: https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/description/?envType=daily-question&envId=2026-06-28

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> mp;
        for(auto &c:arr) mp[min(c,n)]++;

        int ans=1;
        for(int i=2;i<=n;i++){
            ans=min(ans+mp[i],i);
        }
        return ans;
    }
};

// Time Complexity : O(N) + O(N) => O(N);
// Space Complexity: O(N);