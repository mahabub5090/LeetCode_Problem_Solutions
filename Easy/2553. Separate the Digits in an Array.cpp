// Problem Link: https://leetcode.com/problems/separate-the-digits-in-an-array/description/?envType=daily-question&envId=2026-05-11

// class Solution {
// public:
//     vector<int> separateDigits(vector<int>& nums) {
//         vector<int> ans;
//         for(auto &c:nums){
//             stack<int> st;
//             while(c) st.push(c%10),c/=10;
//             while(st.size()) ans.push_back(st.top()),st.pop();
//         }
//         return ans;
//     }
// };

// // Time Complexity : O(N * (2*logN)) => O(NlogN);
// // Space Complexity: O(logN);

// Way: 2 =>

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i=nums.size()-1;i>=0;i--){
            int c=nums[i];
            while(c) ans.push_back(c%10),c/=10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(1);