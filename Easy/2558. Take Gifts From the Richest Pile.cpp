// Problem Link: https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/?envType=daily-question&envId=2024-12-12

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans=0;
        priority_queue<int>pq; for(auto &c:gifts)pq.push(c);
        int cnt=0;
        while(cnt!=k){
            cnt++;
            int c=sqrt(pq.top());
            pq.pop();
            pq.push(c);
        }
        while(pq.size())ans+=pq.top(),pq.pop();
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N); 