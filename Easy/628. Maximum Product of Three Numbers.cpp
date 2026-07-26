// Problem Link: https://leetcode.com/problems/maximum-product-of-three-numbers/description/?envType=daily-question&envId=2026-07-26

// class Solution {
// public:
//     int maximumProduct(vector<int>& nums) {
//         sort(nums.rbegin(),nums.rend());
//         int n=nums.size();
//         return max(nums[0]*nums[1]*nums[2], nums[0]*nums[n-1]*nums[n-2]);
//     }
// };

// // Time Complexity : O(NlogN);
// // Space Complexity: O(1);


// Way: 2 =>

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        priority_queue<int> minQ;
        priority_queue<int, vector<int>, greater<int>> maxQ;
        for(auto &c:nums){
            minQ.push(c);
            maxQ.push(c);

            if(minQ.size()>3) minQ.pop();
            if(maxQ.size()>3) maxQ.pop();
        }

        vector<int> mins, maxs;
        while(minQ.size()) mins.push_back(minQ.top()), minQ.pop();
        while(maxQ.size()) maxs.push_back(maxQ.top()), maxQ.pop();

        int allMax=maxs[2]*maxs[1]*maxs[0];
        int mixed=maxs[2]*mins[2]*mins[1];
        return max(allMax,mixed);
    }
};

// Time Complexity : O(N) + O(3) + O(3) => O(N);
// Space Complexity: O(4) + O(4) + O(3) + O(3) => O(1);