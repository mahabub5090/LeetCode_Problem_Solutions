// Problem Link: https://leetcode.com/problems/maximum-product-of-two-digits/description/?envType=daily-question&envId=2026-07-25

class Solution {
public:
    int maxProduct(int n) {
        priority_queue<int, vector<int>, greater<int>> pq;
        while(n){
            int rem=n%10;
            pq.push(rem);
            if(pq.size()>2) pq.pop();
            n/=10;
        }

        int a=pq.top();pq.pop();
        int b=pq.top();pq.pop();
        return a*b;
    }
};

// Time Complexity : O(logN);
// Space Complexity: O(1);