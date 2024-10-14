// Problem Link: https://leetcode.com/problems/maximal-score-after-applying-k-operations/description/?envType=daily-question&envId=2024-10-14

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        long long ans=0;
        for(int i=0;i<nums.size();i++)pq.push(nums[i]);
        for(int i=0;i<k;i++){
            int c=pq.top();
            pq.pop();
            ans+=c;
            pq.push(ceil(c/3.0));
        }
        return ans;
    }
};

// Time Complexity : O(N + KlogN) => O(NlogN); // K is the number of operations;
// Space Complexity: O(N);