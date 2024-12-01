// Problem Link: https://leetcode.com/problems/check-if-n-and-its-double-exist/?envType=daily-question&envId=2024-12-01

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int>mp;
        for(auto &c:arr)mp[c]++;
        if(mp[0]){
            if(mp[0]>=2)return 1;
        }
        for(auto &c:arr)if(mp[c/2]>0 && c%2==0 && c)return 1;
        return 0;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);