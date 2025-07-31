// Problem Link: https://leetcode.com/problems/bitwise-ors-of-subarrays/description/?envType=daily-question&envId=2025-07-31

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int>ans,curr;
        curr.insert(0);
        for(auto &c:arr){
            set<int>curr2;
            for(auto &cc:curr)curr2.insert(c|cc);
            curr2.insert(c);
            curr=curr2;
            for(auto &cc:curr)ans.insert(cc);
        }
        return ans.size();
    }
};

// Time Complexity : O(N*32) => O(N);
// Space Complextiy: O(N*32) => O(N);