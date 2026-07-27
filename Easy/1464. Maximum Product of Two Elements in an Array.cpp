// Problem Link: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/description/?envType=daily-question&envId=2026-07-27

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<>> pq;
        for(auto &c:nums){
            pq.push(c);
            if(pq.size()>2) pq.pop();
        }
        
        int a=pq.top(); pq.pop();
        int b=pq.top(); pq.pop();
        return (a-1)*(b-1);
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);