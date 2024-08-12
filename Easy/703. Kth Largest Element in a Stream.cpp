// Problem Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/description/?envType=daily-question&envId=2024-08-12

class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int kth;
    KthLargest(int k, vector<int>& nums) {
        kth=k;
        for(auto &c:nums)add(c);
    }    
    int add(int val) {
        if(pq.size()<kth)pq.push(val);
        else if(val>pq.top()){
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

// Time Complexity : Constructor (KthLargest): 𝑂(Nlog⁡K);
//                   add Function: 𝑂(logK) for each call;
// Space Complexity: O(K);

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

