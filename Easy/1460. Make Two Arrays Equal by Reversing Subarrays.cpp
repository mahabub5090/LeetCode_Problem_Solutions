// Problem Link: https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/description/?envType=daily-question&envId=2024-08-03

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto &c:target)mp[c]++;
        for(auto &c:arr){
            if(!mp[c])return 0;
            else mp[c]--;
        }
        return 1;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(N);