// Problem Link: https://leetcode.com/problems/average-waiting-time/description/?envType=daily-question&envId=2024-07-09

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long cnt=0,limit=customers[0][0];
        for(auto &c:customers){
            if(limit>=c[0])limit+=c[1],cnt+=limit-c[0];
            else limit=c[0]+c[1],cnt+=c[1];            
        }
        return cnt*1.0/customers.size();
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);