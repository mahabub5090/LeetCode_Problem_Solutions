// Problem Link: https://leetcode.com/problems/construct-uniform-parity-array-ii/description/?envType=daily-question&envId=2026-09-03

// class Solution {
// public:
//     int helper(int rem, auto &nums){
//         int mn=INT_MAX;
//         for(auto &c:nums){
//             if(c%2) mn=min(mn,c);
//             if(c%2==rem) continue;
//             if(mn<c) continue;
//             return 0;
//         }
//         return 1;
//     }

//     bool uniformArray(vector<int>& nums1) {
//         sort(nums1.begin(),nums1.end());
//         return helper(0,nums1) | helper(1,nums1);
//     }
// };

// // Time Complexity : O(NlogN) + O(N) + O(N) => O(NlogN);
// // Space Complexity: O(1);


// Way: 2 =>

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int oddCnt=0, evenCnt=0;
        int mn=INT_MAX;
        for(auto &c:nums1){
            oddCnt+=c%2;
            evenCnt+=(c%2==0);

            mn=min(mn,c);
        }
        if(oddCnt==0 || evenCnt==0 || mn%2) return 1;
        return 0;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);