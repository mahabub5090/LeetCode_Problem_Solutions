// Problem Link: https://leetcode.com/problems/find-lucky-integer-in-an-array/description/?envType=daily-question&envId=2025-07-05

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto &c:arr)mp[c]++;
        int ans=-1;
        for(auto &[x,y]:mp)if(x==y)ans=max(ans,x);
        return ans;
    }
};

// Time Complexity : O(2*N) => O(N);
// Time Complexity : O(N);