// Problem Link: https://leetcode.com/problems/stone-game/description/?envType=daily-question&envId=2026-08-02

// class Solution {
// public:
//     map<pair<int,int>, int> memo;
//     int solve(int i,int j,auto &nums){
//         if(i==j) return nums[i];
//         if(memo.count({i,j})) return memo[{i,j}];

//         int takeI=nums[i]-solve(i+1,j,nums);
//         int takeJ=nums[j]-solve(i,j-1,nums);
//         return memo[{i,j}]=max(takeI,takeJ);
//     }

//     bool stoneGame(vector<int>& piles) {
//         return solve(0,piles.size()-1,piles) > 0;
//     }
// };

// // Time Complexity : O(N^2);
// // Space Complexity: O(N^2);


// Way: 2 =>

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return 1;
    }
};

// Time Complexity : O(1);
// Space Complexity: O(1);