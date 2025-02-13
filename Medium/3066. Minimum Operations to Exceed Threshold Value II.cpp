// Problem Link: https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/description/?envType=daily-question&envId=2025-02-13

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            priority_queue<long long,vector<long long>,greater<long long>>pq;
            for(auto &c:nums)pq.push(c);
            int ans=0;
            while(pq.top()<k){
                long long a=pq.top();pq.pop();
                long long b=pq.top();pq.pop();
                pq.push(min(a,b)*2+max(a,b));
                ans++;
            }
            return ans;
        }
    };
    
    // Time Complexity : O(N) + O(NlogN) => O(N);
    // Space Complexity: O(N);