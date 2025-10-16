// Problem Link: https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/description/?envType=daily-question&envId=2025-10-16

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int>vc(value,0);
        for(auto &c:nums){
            int val=(c%value+value)%value;
            vc[val]++;
        }

        int ans=0;
        while(vc[ans%value]>0){
            vc[ans%value]--;
            ans++;
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);