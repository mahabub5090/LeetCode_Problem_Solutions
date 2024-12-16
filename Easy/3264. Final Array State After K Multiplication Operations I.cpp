// Problem Link: https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/submissions/1480209770/?envType=daily-question&envId=2024-12-16

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k--){
            int mn=*min_element(nums.begin(),nums.end());
            for(auto &c:nums){
                if(c==mn){
                    c*=multiplier;
                    break;
                }
            }
        }
        return nums;
    }
};

// Time Complexity : O(k*N) => O(N^2);
// Space Complexity: O(1);

// Way: 2 =>

// class Solution {
// public:
//     vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
//         auto cmp=[](auto &a,auto &b){
//             if(a.first==b.first)return a.second>b.second;
//             return a.first>b.first;
//         };
//         priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)>pq(cmp);
//         for(int i=0;i<nums.size();i++){
//             pq.push({nums[i],i});
//         }
//         while(k--){
//             auto c=pq.top();
//             pq.pop();
//             pq.push({c.first*multiplier,c.second});
//         }
//         vector<int>ans(nums.size());
//         while(pq.size()){
//             auto c=pq.top();
//             pq.pop();
//             ans[c.second]=c.first;
//         }
//         return ans;
//     }
// };

// Time Complexity : O(KlogN + NlogN) => O(NlogN);
// Space Complexity: O(N);