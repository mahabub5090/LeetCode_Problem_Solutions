// Problem Link: https://leetcode.com/problems/partition-array-according-to-given-pivot/description/?envType=daily-question&envId=2025-03-03
// Problem Link: https://leetcode.com/problems/partition-array-according-to-given-pivot/description/?envType=daily-question&envId=2026-06-08

// // class Solution {
// // public:
// //     vector<int> pivotArray(vector<int>& nums, int pivot) {
// //         vector<int>ans;
// //         for(auto &c:nums)if(c<pivot)ans.push_back(c);
// //         for(auto &c:nums)if(c==pivot)ans.push_back(c);
// //         for(auto &c:nums)if(c>pivot)ans.push_back(c);
// //         return ans;
// //     }
// // };

// // // Time Complexity : O(3*N) => O(N);
// // // Space Complexity: O(N);


// // Way: 2 =>

// class Solution {
// public:
//     vector<int> pivotArray(vector<int>& nums, int pivot) {
//         queue<int> q;
//         vector<int> ans;
//         int equal=0;
//         for(auto &c:nums){
//             if(c==pivot) equal++;
//             else if(c<pivot) ans.push_back(c);
//             else q.push(c);
//         }
//         for(int i=0;i<equal;i++) ans.push_back(pivot);
//         while(q.size()){
//             int c=q.front();
//             q.pop();
//             ans.push_back(c);
//         }
//         return ans;
//     }
// };

// // Time Complexity : O(N) + O(X) + O(Y) => O(N) + O(N) => O(N);
// // Space Complexity: O(N) + O(N) => O(N);
// // X=equal element of pivot and Y=greater of element pivot, so X+Y<=N;


// Way: 3 =>

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int> ans(n,0);
        int i=0, j=n-1;
        int lessCnt=i, greaterCnt=j;
        while(i<n){
            if(nums[i]<pivot) ans[lessCnt++]=nums[i];
            if(nums[j]>pivot) ans[greaterCnt--]=nums[j];
            i++,j--;
        }
        while(lessCnt<=greaterCnt) ans[lessCnt++]=pivot;
        return ans;
    }
};

// Time Complexity : O(N) + O(X) => O(N);
// Space Complexity: O(N);
// X=X=equal numbers of element of pivot;