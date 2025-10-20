// Problem Link: https://leetcode.com/problems/final-value-of-variable-after-performing-operations/description/?envType=daily-question&envId=2025-10-20

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans=0;
        for(auto &c:operations){
            ans+=(c[0]=='+' || c.back()=='+')?1:-1;
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);